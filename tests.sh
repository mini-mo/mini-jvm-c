#!/usr/bin/env bash
set -e

ROOT_PATH=$(cd "$(dirname "$0")";pwd)
RED='\033[0;31m'
GREEN='\033[0;32m'
NO_COLOR='\033[0m'

function run_one() {
  exe=$1
  test=$2
  echo -n "Running $test, $3 ..."

  pushd tests/$test > /dev/null
  R="./test.sh $exe"

  # run
  $R > test.result

  if [[ 0 -eq $? ]]; then
    echo -e "${GREEN} Passed${NO_COLOR}"
  else
    echo -e "${RED} Failed $2. Aborting.${NO_COLOR}"
    exit 1
  fi
  popd > /dev/null
}

run_one ${ROOT_PATH}/jvm sum10 "sum10"
run_one ${ROOT_PATH}/jvm constants "constants instructions"
