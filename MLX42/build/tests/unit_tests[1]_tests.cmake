add_test([=[MLX42.Window.Basic]=]  /Users/rel-mora/Desktop/so_long/MLX42/build/unit_tests [==[--gtest_filter=Window.Basic]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[MLX42.Window.Basic]=]  PROPERTIES WORKING_DIRECTORY /Users/rel-mora/Desktop/so_long/MLX42/tests SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test([=[MLX42.Window.SingleImage]=]  /Users/rel-mora/Desktop/so_long/MLX42/build/unit_tests [==[--gtest_filter=Window.SingleImage]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[MLX42.Window.SingleImage]=]  PROPERTIES WORKING_DIRECTORY /Users/rel-mora/Desktop/so_long/MLX42/tests SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test([=[MLX42.Window.MultipleImages]=]  /Users/rel-mora/Desktop/so_long/MLX42/build/unit_tests [==[--gtest_filter=Window.MultipleImages]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[MLX42.Window.MultipleImages]=]  PROPERTIES WORKING_DIRECTORY /Users/rel-mora/Desktop/so_long/MLX42/tests SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test([=[MLX42.Window.stringTortureTest]=]  /Users/rel-mora/Desktop/so_long/MLX42/build/unit_tests [==[--gtest_filter=Window.stringTortureTest]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[MLX42.Window.stringTortureTest]=]  PROPERTIES WORKING_DIRECTORY /Users/rel-mora/Desktop/so_long/MLX42/tests SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test([=[MLX42.MWindow.Settings]=]  /Users/rel-mora/Desktop/so_long/MLX42/build/unit_tests [==[--gtest_filter=MWindow.Settings]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[MLX42.MWindow.Settings]=]  PROPERTIES WORKING_DIRECTORY /Users/rel-mora/Desktop/so_long/MLX42/tests SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set(  unit_tests_TESTS MLX42.Window.Basic MLX42.Window.SingleImage MLX42.Window.MultipleImages MLX42.Window.stringTortureTest MLX42.MWindow.Settings)
