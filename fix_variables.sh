#!/bin/bash

# Use find to generate a list of .cc files
cc_files_list=$(find ./src/ -type f -name "*.cc")

# Iterate through the list of .cc files and process each file
for file in $cc_files_list; do
    # Perform replacements using sed and save to a temporary file
    sed -E 's/\bunsigned[[:space:]]+int\b/uint32_t/g;
            s/\bunsigned[[:space:]]+char\b/uint8_t/g;
            s/\bunsigned[[:space:]]+short\b/uint16_t/g;
            s/\bunsigned[[:space:]]+long\b/uint64_t/g;
            s/\bshort[[:space:]]+int\b/int16_t/g;
            s/\bint\b/int32_t/g;
            s/\bdouble\b/double/g;
            s/\bfloat\b/float/g;
            s/\bchar\b/char/g;
            s/\bshort\b/int16_t/g;
            s/\blong\b/int64_t/g;' "$file" > "$file.tmp"
    
    # Overwrite the original file with the temporary file
    mv "$file.tmp" "$file"
done
