
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/file.h"
#include "kernel/require.h"
#include "kernel/string.h"
#include "ext/spl/spl_exceptions.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Cli\Console
 *
 * This component allows to create CLI applications using Phalcon
 */
ZEPHIR_INIT_CLASS(Phalcon_Cli_Console) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Cli, Console, phalcon, cli_console, phalcon_application_ce, phalcon_cli_console_method_entry, 0);

	zend_declare_property_null(phalcon_cli_console_ce, SL("_arguments"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_cli_console_ce, SL("_options"), ZEND_ACC_PROTECTED TSRMLS_CC);

	phalcon_cli_console_ce->create_object = zephir_init_properties_Phalcon_Cli_Console;
	return SUCCESS;

}

/**
 * Handle the whole command-line tasks
 */
PHP_METHOD(Phalcon_Cli_Console, handle) {

	zend_bool _5;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *arguments_param = NULL, __$false, dependencyInjector, router, eventsManager, moduleName, modules, module, path, className, moduleObject, dispatcher, task, _0, _3, _4, _15, _16, _17, _18, _1$$4, _2$$4, _6$$6, _7$$10, _8$$10, _9$$12, _10$$12, _11$$17, _12$$17, _13$$18, _14$$18, _19$$20, _20$$20, _21$$22;
	zval arguments;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&arguments);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&dependencyInjector);
	ZVAL_UNDEF(&router);
	ZVAL_UNDEF(&eventsManager);
	ZVAL_UNDEF(&moduleName);
	ZVAL_UNDEF(&modules);
	ZVAL_UNDEF(&module);
	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&moduleObject);
	ZVAL_UNDEF(&dispatcher);
	ZVAL_UNDEF(&task);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_7$$10);
	ZVAL_UNDEF(&_8$$10);
	ZVAL_UNDEF(&_9$$12);
	ZVAL_UNDEF(&_10$$12);
	ZVAL_UNDEF(&_11$$17);
	ZVAL_UNDEF(&_12$$17);
	ZVAL_UNDEF(&_13$$18);
	ZVAL_UNDEF(&_14$$18);
	ZVAL_UNDEF(&_19$$20);
	ZVAL_UNDEF(&_20$$20);
	ZVAL_UNDEF(&_21$$22);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &arguments_param);

	if (!arguments_param) {
		ZEPHIR_INIT_VAR(&arguments);
		array_init(&arguments);
	} else {
		zephir_get_arrval(&arguments, arguments_param);
	}


	ZEPHIR_OBS_VAR(&dependencyInjector);
	zephir_read_property(&dependencyInjector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if (Z_TYPE_P(&dependencyInjector) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cli_console_exception_ce, "A dependency injection object is required to access internal services", "phalcon/cli/console.zep", 42);
		return;
	}
	zephir_read_property(&_0, this_ptr, SL("_eventsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&eventsManager, &_0);
	if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_2$$4);
		ZVAL_STRING(&_2$$4, "console:boot");
		ZEPHIR_CALL_METHOD(&_1$$4, &eventsManager, "fire", NULL, 0, &_2$$4, this_ptr);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_1$$4)) {
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "router");
	ZEPHIR_CALL_METHOD(&_3, &dependencyInjector, "getshared", NULL, 0, &_4);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&router, &_3);
	_5 = !(zephir_fast_count_int(&arguments TSRMLS_CC));
	if (_5) {
		zephir_read_property(&_0, this_ptr, SL("_arguments"), PH_NOISY_CC | PH_READONLY);
		_5 = zephir_is_true(&_0);
	}
	if (_5) {
		zephir_read_property(&_6$$6, this_ptr, SL("_arguments"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &router, "handle", NULL, 0, &_6$$6);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &router, "handle", NULL, 0, &arguments);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&moduleName, &router, "getmodulename", NULL, 0);
	zephir_check_call_status();
	if (!(zephir_is_true(&moduleName))) {
		ZEPHIR_OBS_NVAR(&moduleName);
		zephir_read_property(&moduleName, this_ptr, SL("_defaultModule"), PH_NOISY_CC);
	}
	if (zephir_is_true(&moduleName)) {
		if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
			ZEPHIR_INIT_VAR(&_8$$10);
			ZVAL_STRING(&_8$$10, "console:beforeStartModule");
			ZEPHIR_CALL_METHOD(&_7$$10, &eventsManager, "fire", NULL, 0, &_8$$10, this_ptr, &moduleName);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(&_7$$10)) {
				RETURN_MM_BOOL(0);
			}
		}
		ZEPHIR_OBS_VAR(&modules);
		zephir_read_property(&modules, this_ptr, SL("_modules"), PH_NOISY_CC);
		if (!(zephir_array_isset(&modules, &moduleName))) {
			ZEPHIR_INIT_VAR(&_9$$12);
			object_init_ex(&_9$$12, phalcon_cli_console_exception_ce);
			ZEPHIR_INIT_VAR(&_10$$12);
			ZEPHIR_CONCAT_SVS(&_10$$12, "Module '", &moduleName, "' isn't registered in the console container");
			ZEPHIR_CALL_METHOD(NULL, &_9$$12, "__construct", NULL, 4, &_10$$12);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_9$$12, "phalcon/cli/console.zep", 82 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_OBS_VAR(&module);
		zephir_array_fetch(&module, &modules, &moduleName, PH_NOISY, "phalcon/cli/console.zep", 85 TSRMLS_CC);
		if (Z_TYPE_P(&module) != IS_ARRAY) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cli_console_exception_ce, "Invalid module definition path", "phalcon/cli/console.zep", 87);
			return;
		}
		ZEPHIR_OBS_VAR(&className);
		if (!(zephir_array_isset_string_fetch(&className, &module, SL("className"), 0))) {
			ZEPHIR_INIT_NVAR(&className);
			ZVAL_STRING(&className, "Module");
		}
		ZEPHIR_OBS_VAR(&path);
		if (zephir_array_isset_string_fetch(&path, &module, SL("path"), 0)) {
			if (!(zephir_class_exists(&className, zephir_is_true(&__$false)  TSRMLS_CC))) {
				if (!((zephir_file_exists(&path TSRMLS_CC) == SUCCESS))) {
					ZEPHIR_INIT_VAR(&_11$$17);
					object_init_ex(&_11$$17, phalcon_cli_console_exception_ce);
					ZEPHIR_INIT_VAR(&_12$$17);
					ZEPHIR_CONCAT_SVS(&_12$$17, "Module definition path '", &path, "' doesn't exist");
					ZEPHIR_CALL_METHOD(NULL, &_11$$17, "__construct", NULL, 4, &_12$$17);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_11$$17, "phalcon/cli/console.zep", 97 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (zephir_require_zval(&path TSRMLS_CC) == FAILURE) {
					RETURN_MM_NULL();
				}
			}
		}
		ZEPHIR_CALL_METHOD(&moduleObject, &dependencyInjector, "get", NULL, 0, &className);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &moduleObject, "registerautoloaders", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &moduleObject, "registerservices", NULL, 0, &dependencyInjector);
		zephir_check_call_status();
		if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
			ZEPHIR_INIT_VAR(&_14$$18);
			ZVAL_STRING(&_14$$18, "console:afterStartModule");
			ZEPHIR_CALL_METHOD(&_13$$18, &eventsManager, "fire", NULL, 0, &_14$$18, this_ptr, &moduleObject);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(&_13$$18)) {
				RETURN_MM_BOOL(0);
			}
		}
	}
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "dispatcher");
	ZEPHIR_CALL_METHOD(&_3, &dependencyInjector, "getshared", NULL, 0, &_4);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&dispatcher, &_3);
	ZEPHIR_CALL_METHOD(&_3, &router, "getmodulename", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &dispatcher, "setmodulename", NULL, 0, &_3);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_15, &router, "gettaskname", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &dispatcher, "settaskname", NULL, 0, &_15);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_16, &router, "getactionname", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &dispatcher, "setactionname", NULL, 0, &_16);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_17, &router, "getparams", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &dispatcher, "setparams", NULL, 0, &_17);
	zephir_check_call_status();
	zephir_read_property(&_18, this_ptr, SL("_options"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &dispatcher, "setoptions", NULL, 0, &_18);
	zephir_check_call_status();
	if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_20$$20);
		ZVAL_STRING(&_20$$20, "console:beforeHandleTask");
		ZEPHIR_CALL_METHOD(&_19$$20, &eventsManager, "fire", NULL, 0, &_20$$20, this_ptr, &dispatcher);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_19$$20)) {
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_CALL_METHOD(&task, &dispatcher, "dispatch", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_21$$22);
		ZVAL_STRING(&_21$$22, "console:afterHandleTask");
		ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", NULL, 0, &_21$$22, this_ptr, &task);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&task);

}

/**
 * Set an specific argument
 */
PHP_METHOD(Phalcon_Cli_Console, setArgument) {

	zephir_fcall_cache_entry *_5 = NULL, *_24 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool str, shift, _0;
	zval *arguments_param = NULL, *str_param = NULL, *shift_param = NULL, __$true, arg, pos, args, opts, handleArgs, *_1, _2$$5, _3$$5, _4$$5, _6$$6, _7$$7, _8$$7, _9$$7, _10$$7, _11$$7, _12$$7, _13$$7, _14$$8, _15$$8, _16$$8, _17$$9, _18$$9, _19$$9, _20$$10, _21$$10, _22$$13, _23$$13, _25$$15, _26$$16, _27$$17;
	zval arguments;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&arguments);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&arg);
	ZVAL_UNDEF(&pos);
	ZVAL_UNDEF(&args);
	ZVAL_UNDEF(&opts);
	ZVAL_UNDEF(&handleArgs);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_11$$7);
	ZVAL_UNDEF(&_12$$7);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&_14$$8);
	ZVAL_UNDEF(&_15$$8);
	ZVAL_UNDEF(&_16$$8);
	ZVAL_UNDEF(&_17$$9);
	ZVAL_UNDEF(&_18$$9);
	ZVAL_UNDEF(&_19$$9);
	ZVAL_UNDEF(&_20$$10);
	ZVAL_UNDEF(&_21$$10);
	ZVAL_UNDEF(&_22$$13);
	ZVAL_UNDEF(&_23$$13);
	ZVAL_UNDEF(&_25$$15);
	ZVAL_UNDEF(&_26$$16);
	ZVAL_UNDEF(&_27$$17);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 3, &arguments_param, &str_param, &shift_param);

	if (!arguments_param) {
		ZEPHIR_INIT_VAR(&arguments);
		array_init(&arguments);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&arguments, arguments_param);
	}
	if (!str_param) {
		str = 1;
	} else {
	if (UNEXPECTED(Z_TYPE_P(str_param) != IS_TRUE && Z_TYPE_P(str_param) != IS_FALSE)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'str' must be of the type bool") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	str = (Z_TYPE_P(str_param) == IS_TRUE);
	}
	if (!shift_param) {
		shift = 1;
	} else {
	if (UNEXPECTED(Z_TYPE_P(shift_param) != IS_TRUE && Z_TYPE_P(shift_param) != IS_FALSE)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'shift' must be of the type bool") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	shift = (Z_TYPE_P(shift_param) == IS_TRUE);
	}


	ZEPHIR_INIT_VAR(&args);
	array_init(&args);
	ZEPHIR_INIT_VAR(&opts);
	array_init(&opts);
	ZEPHIR_INIT_VAR(&handleArgs);
	array_init(&handleArgs);
	_0 = shift;
	if (_0) {
		_0 = ((zephir_fast_count_int(&arguments TSRMLS_CC)) ? 1 : 0);
	}
	if (_0) {
		ZEPHIR_MAKE_REF(&arguments);
		ZEPHIR_CALL_FUNCTION(NULL, "array_shift", NULL, 11, &arguments);
		ZEPHIR_UNREF(&arguments);
		zephir_check_call_status();
	}
	zephir_is_iterable(&arguments, 0, "phalcon/cli/console.zep", 176);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&arguments), _1)
	{
		ZEPHIR_INIT_NVAR(&arg);
		ZVAL_COPY(&arg, _1);
		if (Z_TYPE_P(&arg) == IS_STRING) {
			ZEPHIR_INIT_NVAR(&_2$$5);
			ZVAL_STRING(&_2$$5, "--");
			ZVAL_LONG(&_3$$5, 2);
			ZEPHIR_CALL_FUNCTION(&_4$$5, "strncmp", &_5, 116, &arg, &_2$$5, &_3$$5);
			zephir_check_call_status();
			if (ZEPHIR_IS_LONG(&_4$$5, 0)) {
				ZEPHIR_INIT_NVAR(&_6$$6);
				ZVAL_STRING(&_6$$6, "=");
				ZEPHIR_INIT_NVAR(&pos);
				zephir_fast_strpos(&pos, &arg, &_6$$6, 0 );
				if (zephir_is_true(&pos)) {
					ZEPHIR_INIT_NVAR(&_7$$7);
					ZVAL_LONG(&_8$$7, (zephir_get_numberval(&pos) + 1));
					ZEPHIR_INIT_NVAR(&_9$$7);
					zephir_substr(&_9$$7, &arg, zephir_get_intval(&_8$$7), 0, ZEPHIR_SUBSTR_NO_LENGTH);
					zephir_fast_trim(&_7$$7, &_9$$7, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
					ZEPHIR_INIT_NVAR(&_10$$7);
					ZVAL_LONG(&_11$$7, 2);
					ZVAL_LONG(&_12$$7, (zephir_get_numberval(&pos) - 2));
					ZEPHIR_INIT_NVAR(&_13$$7);
					zephir_substr(&_13$$7, &arg, 2 , zephir_get_intval(&_12$$7), 0);
					zephir_fast_trim(&_10$$7, &_13$$7, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
					zephir_array_update_zval(&opts, &_10$$7, &_7$$7, PH_COPY | PH_SEPARATE);
				} else {
					ZEPHIR_INIT_NVAR(&_14$$8);
					ZVAL_LONG(&_15$$8, 2);
					ZEPHIR_INIT_NVAR(&_16$$8);
					zephir_substr(&_16$$8, &arg, 2 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
					zephir_fast_trim(&_14$$8, &_16$$8, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
					zephir_array_update_zval(&opts, &_14$$8, &__$true, PH_COPY | PH_SEPARATE);
				}
			} else {
				ZEPHIR_INIT_NVAR(&_17$$9);
				ZVAL_STRING(&_17$$9, "-");
				ZVAL_LONG(&_18$$9, 1);
				ZEPHIR_CALL_FUNCTION(&_19$$9, "strncmp", &_5, 116, &arg, &_17$$9, &_18$$9);
				zephir_check_call_status();
				if (ZEPHIR_IS_LONG(&_19$$9, 0)) {
					ZVAL_LONG(&_20$$10, 1);
					ZEPHIR_INIT_NVAR(&_21$$10);
					zephir_substr(&_21$$10, &arg, 1 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
					zephir_array_update_zval(&opts, &_21$$10, &__$true, PH_COPY | PH_SEPARATE);
				} else {
					zephir_array_append(&args, &arg, PH_SEPARATE, "phalcon/cli/console.zep", 168);
				}
			}
		} else {
			zephir_array_append(&args, &arg, PH_SEPARATE, "phalcon/cli/console.zep", 172);
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&arg);
	if (str) {
		ZEPHIR_INIT_VAR(&_22$$13);
		ZEPHIR_CALL_CE_STATIC(&_23$$13, phalcon_cli_router_route_ce, "getdelimiter", &_24, 0);
		zephir_check_call_status();
		zephir_fast_join(&_22$$13, &_23$$13, &args TSRMLS_CC);
		zephir_update_property_zval(this_ptr, SL("_arguments"), &_22$$13);
	} else {
		if (zephir_fast_count_int(&args TSRMLS_CC)) {
			ZEPHIR_MAKE_REF(&args);
			ZEPHIR_CALL_FUNCTION(&_25$$15, "array_shift", NULL, 11, &args);
			ZEPHIR_UNREF(&args);
			zephir_check_call_status();
			zephir_array_update_string(&handleArgs, SL("task"), &_25$$15, PH_COPY | PH_SEPARATE);
		}
		if (zephir_fast_count_int(&args TSRMLS_CC)) {
			ZEPHIR_MAKE_REF(&args);
			ZEPHIR_CALL_FUNCTION(&_26$$16, "array_shift", NULL, 11, &args);
			ZEPHIR_UNREF(&args);
			zephir_check_call_status();
			zephir_array_update_string(&handleArgs, SL("action"), &_26$$16, PH_COPY | PH_SEPARATE);
		}
		if (zephir_fast_count_int(&args TSRMLS_CC)) {
			ZEPHIR_INIT_VAR(&_27$$17);
			zephir_fast_array_merge(&_27$$17, &handleArgs, &args TSRMLS_CC);
			ZEPHIR_CPY_WRT(&handleArgs, &_27$$17);
		}
		zephir_update_property_zval(this_ptr, SL("_arguments"), &handleArgs);
	}
	zephir_update_property_zval(this_ptr, SL("_options"), &opts);
	RETURN_THIS();

}

zend_object *zephir_init_properties_Phalcon_Cli_Console(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _2, _4, _1$$3, _3$$4, _5$$5;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$5);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("_options"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("_options"), &_1$$3);
		}
		zephir_read_property(&_2, this_ptr, SL("_modules"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval(this_ptr, SL("_modules"), &_3$$4);
		}
		zephir_read_property(&_4, this_ptr, SL("_arguments"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_4) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_5$$5);
			array_init(&_5$$5);
			zephir_update_property_zval(this_ptr, SL("_arguments"), &_5$$5);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

