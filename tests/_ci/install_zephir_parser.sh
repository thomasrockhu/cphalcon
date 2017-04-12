#!/usr/bin/env bash
#
#  Phalcon Framework
#
#  Copyright (c) 2011-2017 Phalcon Team (https://www.phalconphp.com)
#
#  This source file is subject to the New BSD License that is bundled
#  with this package in the file docs/LICENSE.txt.
#
#  If you did not receive a copy of the license and are unable to
#  obtain it through the world-wide-web, please send an email
#  to license@phalconphp.com so we can send you a copy immediately.

echo -e "Install Zephir Parser..."

CURRENT_DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
TRAVIS_BUILD_DIR="${TRAVIS_BUILD_DIR:-$(dirname $(dirname $CURRENT_DIR))}"

PARSER_DIR=$HOME/zephir-parser

# Use Travis Cache
if [ ! -f ${PARSER_DIR}/tests/ci/install-travis ]; then
	git clone --depth=1 -v https://github.com/phalcon/php-zephir-parser.git -b $ZEPHIR_PARSER_VERSION ${PARSER_DIR}
fi

cd ${PARSER_DIR}

# Only for Travis CI
TRAVIS_BUILD_DIR=$(pwd) bash ./tests/ci/install-travis

cd ${TRAVIS_BUILD_DIR}
