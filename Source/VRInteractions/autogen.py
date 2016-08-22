import re

# THE PLAN
# Do everything with blueprint native events because those can have C++
# implementations that can be overridden by blueprints.
# Screw interfaces, just copy-paste the same methods around.

def main():
    # Define arrays and dicts for results
    hand_headers = []
    empty_headers = []
    hand_passthroughs = []
    input_bindings = {'left': [], 'right': []}

    with open('MotionControllerEventDefinitions.txt', 'r') as f:
        contents = f.read();

        # Read the classes to write methods for
        hand_class = re.findall(r'HAND_CLASS\s*=\s*([a-zA-Z0-9_]+)', contents)[0]

        # Read the UFUNCTION headers
        hand_ufunction = re.search(r'HAND_UFUNCTION\s*=\s*(.*)', contents).group(1)
        empty_implementation_ufunction = re.search(r'EMPTY_IMPLEMENTATION_UFUNCTION\s*=\s*(.*)', contents).group(1)

        # Match all the events!
        event_matches = re.findall(r'^([a-zA-Z0-9_]+)\((.*)\)(;?\s*#\s*([a-zA-Z0-9_]+))?', contents, re.M)
        for event in event_matches:
            event_name = event[0]
            event_params = event[1]
            event_ekeys = event[3]

            treat_as_axis = False
            meta_match = re.search(r'([a-zA-Z0-9_]+)(Pressed|Released)', event_name)
            if meta_match:
                event_action = meta_match.group(2)
                if not event_ekeys:
                    event_ekeys = meta_match.group(1)
            else:
                event_ekeys = event_ekeys or event_name
                treat_as_axis = True

            # Pull out just param names for later use
            event_param_names = re.findall(r'[^ ,]+\s+([^ ,]+)', event_params)

            # Generate the code
            hand_header = ''
            hand_header += hand_ufunction + '\n'
            hand_header += 'void ' + event_name + '(' + event_params + ');\n'
            hand_headers.append(hand_header)

            empty_header = ''
            empty_header += empty_implementation_ufunction + '\n'
            empty_header += 'void ' + event_name + '(' + event_params + ');\n'
            empty_headers.append(empty_header)

            passthrough = ''
            passthrough += 'void ' + hand_class + '::' + event_name + '_Implementation(' + event_params + ') {\n'
            passthrough += '    if (Interacting->IsValidLowLevel()) {\n'
            passthrough += '        Interacting->' + event_name + '(' + ', '.join(event_param_names) + ');\n'
            passthrough += '    } else if (Grabbed->IsValidLowLevel()) {\n'
            passthrough += '        Grabbed->' + event_name + '(' + ', '.join(event_param_names) + ');\n'
            passthrough += '    }\n'
            passthrough += '}\n'
            hand_passthroughs.append(passthrough)

            if treat_as_axis:
                ib_left = 'InputComponent->BindAxisKey(EKeys::MotionController_Left_' + event_ekeys + ', this, &' + hand_class + '::' + event_name + ');\n'
                ib_right = 'InputComponent->BindAxisKey(EKeys::MotionController_Right_' + event_ekeys + ', this, &' + hand_class + '::' + event_name + ');\n'
            else:
                ib_left = 'InputComponent->BindKey(EKeys::MotionController_Left_' + event_ekeys + ', EInputEvent::IE_' + event_action + ', this, &' + hand_class + '::' + event_name + ');\n'
                ib_right = 'InputComponent->BindKey(EKeys::MotionController_Right_' + event_ekeys + ', EInputEvent::IE_' + event_action + ', this, &' + hand_class + '::' + event_name + ');\n'
            input_bindings['left'].append(ib_left)
            input_bindings['right'].append(ib_right)

    with open('autogen_result.txt', 'w') as out:
        out.write('//==============================================================================\n')
        out.write('// Hand Headers\n')
        out.write('//==============================================================================\n')
        out.write('\n')

        for header in hand_headers:
            out.write(header)
            out.write('\n')

        out.write('//==============================================================================\n')
        out.write('// Hand Input Bindings\n')
        out.write('//==============================================================================\n')
        out.write('\n')

        out.write('if (MotionController->Hand == EControllerHand::Left) {\n')
        for ib in input_bindings['left']:
            out.write('\t' + ib)
        out.write('} else if (MotionController->Hand == EControllerHand::Right) {\n')
        for ib in input_bindings['right']:
            out.write('\t' + ib)
        out.write('}\n')
        out.write('\n')

        out.write('//==============================================================================\n')
        out.write('// Empty Implementation Headers\n')
        out.write('//==============================================================================\n')
        out.write('\n')

        for header in empty_headers:
            out.write(header)
            out.write('\n')

        out.write('//==============================================================================\n')
        out.write('// Hand Passthroughs\n')
        out.write('//==============================================================================\n')
        out.write('\n')

        for passthrough in hand_passthroughs:
            out.write(passthrough)
            out.write('\n')

    
if __name__ == "__main__":
    main()
