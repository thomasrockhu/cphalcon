<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Integration\Session\Adapter\Stream;

use IntegrationTester;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Fixtures\Traits\SessionTrait;

use function cacheDir;
use function uniqid;

class ReadCest
{
    use DiTrait;

    /**
     * Tests Phalcon\Session\Adapter\Stream :: write()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function sessionAdapterStreamRead(IntegrationTester $I)
    {
        $I->wantToTest('Session\Adapter\Stream - write()');

        $adapter = $this->newService('sessionStream');

        $value = uniqid();

        $adapter->write('test1', $value);

        $I->assertEquals(
            $value,
            $adapter->read('test1')
        );

        $I->safeDeleteFile(
            cacheDir('sessions/test1')
        );
    }
}
