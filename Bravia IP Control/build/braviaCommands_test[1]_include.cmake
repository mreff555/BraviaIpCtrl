if(EXISTS "/Users/mreff555/src/BraviaIpCtrl/Bravia IP Control/build/braviaCommands_test[1]_tests.cmake")
  include("/Users/mreff555/src/BraviaIpCtrl/Bravia IP Control/build/braviaCommands_test[1]_tests.cmake")
else()
  add_test(braviaCommands_test_NOT_BUILT braviaCommands_test_NOT_BUILT)
endif()