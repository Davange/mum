#!/bin/bash

# Prompt the user for a command
echo "Enter a command:"
read command

# Use a case statement to execute the appropriate command
case $command in
  "ls")
    ls
    ;;
  "pwd")
    pwd
    ;;
  "whoami")
    whoami
    ;;
  *)
    echo "Invalid command"
    ;;
esac
