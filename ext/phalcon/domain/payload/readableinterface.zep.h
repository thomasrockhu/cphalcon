
extern zend_class_entry *phalcon_domain_payload_readableinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Domain_Payload_ReadableInterface);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_domain_payload_readableinterface_getexception, 0, 0, Throwable, 1)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_domain_payload_readableinterface_getexception, 0, 0, IS_OBJECT, "Throwable", 1)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_domain_payload_readableinterface_getextras, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_domain_payload_readableinterface_getinput, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_domain_payload_readableinterface_getmessages, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_domain_payload_readableinterface_getoutput, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_domain_payload_readableinterface_getstatus, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_domain_payload_readableinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Domain_Payload_ReadableInterface, getException, arginfo_phalcon_domain_payload_readableinterface_getexception)
	PHP_ABSTRACT_ME(Phalcon_Domain_Payload_ReadableInterface, getExtras, arginfo_phalcon_domain_payload_readableinterface_getextras)
	PHP_ABSTRACT_ME(Phalcon_Domain_Payload_ReadableInterface, getInput, arginfo_phalcon_domain_payload_readableinterface_getinput)
	PHP_ABSTRACT_ME(Phalcon_Domain_Payload_ReadableInterface, getMessages, arginfo_phalcon_domain_payload_readableinterface_getmessages)
	PHP_ABSTRACT_ME(Phalcon_Domain_Payload_ReadableInterface, getOutput, arginfo_phalcon_domain_payload_readableinterface_getoutput)
	PHP_ABSTRACT_ME(Phalcon_Domain_Payload_ReadableInterface, getStatus, arginfo_phalcon_domain_payload_readableinterface_getstatus)
	PHP_FE_END
};
