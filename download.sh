download()
{
    if [[ -z "$1" ]] || [[ -z "$2" ]]
    then
        echo "Download sample submission file from list"
        echo "Usage:"
        echo "  download [list file] [language]"
        return -1
    else
        cat $1 | tac | while read line;
        do
            index=$(echo $line | grep -o '[0-9]\+' | awk '{ print $1 }' | head -1)
            if [[ -z $index ]]; then continue; fi
            file=$(find . -name "$index.*.$2")
            if [[ -z $file ]]
            then
                sleep 1s
                flag=$(leetcode show $index -gx -l $2 | grep ERROR)
                if [[ -z $flag ]]
                then
                    echo "Download No: $index in .$2"
                    flag="downloaded"
                    break
                else
                    echo "Download No: $index in .$2 Failed: $flag"
                fi;
            fi
        done
        if [[ $flag != "downloaded" ]]; then echo "All problems in $1 solved."; fi;
    fi
}
