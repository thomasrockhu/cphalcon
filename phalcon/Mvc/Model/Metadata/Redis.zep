
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Mvc\Model\MetaData;

use Phalcon\Mvc\Model\MetaData;
use Phalcon\Cache\Backend\Redis;
use Phalcon\Cache\Frontend\Data as FrontendData;

/**
 * Phalcon\Mvc\Model\MetaData\Redis
 *
 * Stores model meta-data in the Redis.
 *
 * By default meta-data is stored for 48 hours (172800 seconds)
 *
 *<code>
 * use Phalcon\Mvc\Model\Metadata\Redis;
 *
 * $metaData = new Redis(
 *     [
 *         "host"       => "127.0.0.1",
 *         "port"       => 6379,
 *         "persistent" => 0,
 *         "statsKey"   => "_PHCM_MM",
 *         "lifetime"   => 172800,
 *         "index"      => 2,
 *     ]
 * );
 *</code>
 */
class Redis extends MetaData
{
    protected metaData = [];

    protected redis = null;

    protected ttl = 172800;

    /**
     * Phalcon\Mvc\Model\MetaData\Redis constructor
     *
     * @param array options
     */
    public function __construct(options = null) -> void
    {
        var ttl;

        if typeof options != "array" {
            let options = [];
        }

        if !isset options["statsKey"] {
            let options["statsKey"] = "_PHCM_MM";
        }

        if fetch ttl, options["lifetime"] {
            let this->ttl = ttl;
        }

        let this->redis = new Redis(
            new FrontendData(
                [
                    "lifetime": this->ttl
                ]
            ),
            options
        );
    }

    /**
     * Reads metadata from Redis
     */
    public function read(string! key) -> array | null
    {
        var data;

        let data = this->redis->get(key);
        if typeof data == "array" {
            return data;
        }
        return null;
    }

    /**
     * Writes the metadata to Redis
     */
    public function write(string! key, array data) -> void
    {
        this->redis->save(key, data);
    }

    /**
     * Flush Redis data and resets internal meta-data in order to regenerate it
     */
    public function reset() -> void
    {
        var meta, key, realKey;

        let meta = this->metaData;

        if typeof meta == "array" {
            for key, _ in meta {
                let realKey = "meta-" . key;

                this->redis->delete(realKey);
            }
        }

        parent::reset();
    }
}
