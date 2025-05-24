#include "pch.h"
#include "CppUnitTest.h"
#include "shipping_r.h"
#include "mapping_r.h"
#include <limits>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_MODULE_INITIALIZE(ModuleInitialize)
	{
		Logger::WriteMessage("In Module Initialize");
	}

	TEST_MODULE_CLEANUP(ModuleCleanup)
	{
		Logger::WriteMessage("In Module Cleanup");
	}
	//testing valid baggage weight, Function : checkWeight
	TEST_CLASS(testweightcheck)
	{
	public:
		TEST_CLASS_INITIALIZE(ClassInitialize)
		{
			Logger::WriteMessage("In Class Initialize");
		}

		TEST_CLASS_CLEANUP(ClassCleanup)
		{
			Logger::WriteMessage("In Class Cleanup");
		}


		//positive integer value less than MAX_WEIGHT
		TEST_METHOD(WTS_TestMethod1)
		{
			Logger::WriteMessage("Is the entered argument value a valid value?");

			int result = checkWeight(850);
			Assert::AreEqual(1, result);
		}
		//0value : no weight
		TEST_METHOD(WTS_TestMethod2)
		{
			Logger::WriteMessage("Is the entered argument value a valid value?");

			int result = checkWeight(0);
			Assert::AreEqual(0, result);
		}
		//negative value still integer type
		TEST_METHOD(WTS_TestMethod3)
		{
			Logger::WriteMessage("Is the entered argument value a valid value?");

			int result = checkWeight(-100);
			Assert::AreEqual(0, result);
		}
		//value exceeding MAX_WEIGHT
		TEST_METHOD(WTS_TestMethod4)
		{
			Logger::WriteMessage("Is the entered argument value a valid value?");

			int result = checkWeight(1200);
			Assert::AreEqual(1, result);
		}
		//value which isnt int but number type
		TEST_METHOD(WTS_TestMethod5)
		{
			Logger::WriteMessage("Is the entered argument value a valid value?");

			int result = checkWeight(0.25);
			Assert::AreEqual(0, result);
		}
		// invalid input has inserted
		TEST_METHOD(WTS_TestMethod6)
		{
			Logger::WriteMessage("Is the entered argument value a valid value?");

			int result = checkWeight(NULL);
			Assert::AreEqual(0, result);
		}
		//char type value has been inserted : will cause program failure
		/*TEST_METHOD(WTS_TestMethod7)
		{
			Logger::WriteMessage("Is the entered argument value a valid value?");

			int result = checkWeight("abc / # & $");
			Assert::AreEqual(0, result);
		}*/
	};
	//testing finding truck, Function : getPossibleMove
	TEST_CLASS(testPossibleMoves) {

	public:
		TEST_CLASS_INITIALIZE(ClassInitialize)
		{
			Logger::WriteMessage("In Class Initialize");
		}

		TEST_CLASS_CLEANUP(ClassCleanup)
		{
			Logger::WriteMessage("In Class Cleanup");
		}

		//struct Route getPossibleMoves(const struct Map* map, const struct Point p1, const struct Point backpath)
		TEST_METHOD(TPM_Testcase1)
		{
			Logger::WriteMessage("Check are there poss Point");

			struct Map map = { 0 };
			map.numRows = 5;
			map.numCols = 5;

			struct Point start = { 2, 2 };
			struct Point dest = { 1, 2 };

			struct Route result = getPossibleMoves(&map, start, dest);

			//check route is not null
			Assert::IsNotNull(&result.routeSymbol, L"The route symbol should not be null");

			//check num of point > 0 
			Assert::IsTrue(result.numPoints > 0, L"There should be at least one point in the route");

			//check row, col point is not null
			Assert::IsNotNull(&result.points[0].row, L"The route row point should not be null");
			Assert::IsNotNull(&result.points[0].col, L"The route col point should not be null");
		}

		TEST_METHOD(TPM_Testcase2)
		{
			Logger::WriteMessage("Check are there poss Point");

			struct Map map = { 0 };
			map.numRows = 5;
			map.numCols = 5;

			struct Point start = { 0, 0 };
			struct Point dest = { -1, -1 };

			struct Route result = getPossibleMoves(&map, start, dest);

			//check route is not null
			Assert::IsNotNull(&result.routeSymbol, L"The route symbol should not be null");

			//check num of point > 0 
			Assert::IsTrue(result.numPoints > 0, L"There should be at least one point in the route");

			//check row, col point is not null
			Assert::IsNotNull(&result.points[0].row, L"Invalid Value NUll");
			Assert::IsNotNull(&result.points[0].col, L"Invalid Value NUll");
		}

		TEST_METHOD(TPM_Testcase3)
		{
			Logger::WriteMessage("Check are there poss Point");

			struct Map* map = nullptr;

			struct Point start = { 2, 2 };
			struct Point dest = { 1, 2 };

			struct Route result = getPossibleMoves(map, start, dest);

			//check route is not null
			Assert::IsNotNull(&result.routeSymbol, L"The route symbol should not be null");

			//check num of point > 0 
			Assert::IsTrue(result.numPoints > 0, L"There should be at least one point in the route");

			//check row, col point is not null
			Assert::IsNotNull(&result.points[0].row, L"Invalid Value NUll");
			Assert::IsNotNull(&result.points[0].col, L"Invalid Value NUll");
		}

		TEST_METHOD(TPM_Testcase4)
		{
			Logger::WriteMessage("Check are there poss Point");

			struct Map map = { 0 };
			map.numRows = 5;
			map.numCols = 5;

			struct Point start = { 3, 0 };
			struct Point dest = { 4, 0 };

			struct Route result = getPossibleMoves(&map, start, dest);

			//check route is not null
			Assert::IsNotNull(&result.routeSymbol, L"The route symbol should not be null");

			//check num of point > 0 
			Assert::IsTrue(result.numPoints > 0, L"There should be at least one point in the route");

			//check row, col point is not null
			Assert::IsNotNull(&result.points[0].row, L"Invalid Value NUll");
			Assert::IsNotNull(&result.points[0].col, L"Invalid Value NUll");
		}

	};

	//struct Route shortestPath(const struct Map* map, const struct Point start, const struct Point dest)
	//testing valid box size, Function : shortestPath
	TEST_CLASS(shortPath)
	{
	public:
		TEST_CLASS_INITIALIZE(ClassInitialize)
		{
			Logger::WriteMessage("In Class Initialize");
		}

		TEST_CLASS_CLEANUP(ClassCleanup)
		{
			Logger::WriteMessage("In Class Cleanup");
		}

		TEST_METHOD(STF_TestMethod1)
		{
			Logger::WriteMessage("is it pointing shotest path testcases?");

			struct Map map = { 0 };
			map.numRows = 5;
			map.numCols = 5;

			struct Point start = { 0, 0 };
			struct Point dest = { 4, 4 };

			struct Route result = shortestPath(&map, start, dest);

			//check route is not null
			Assert::IsNotNull(&result.routeSymbol, L"The route symbol should not be null");

			//check num of point > 0 
			Assert::IsTrue(result.numPoints > 0, L"There should be at least one point in the route");

			//check row, col point is not null
			Assert::IsNotNull(&result.points[0].row, L"The route row point should not be null");
			Assert::IsNotNull(&result.points[0].col, L"The route col point should not be null");
		}

		TEST_METHOD(STF_TestMethod2)
		{
			Logger::WriteMessage("is it pointing shotest path testcases?");

			struct Map map = { 0 };
			map.numRows = 5;
			map.numCols = 5;

			struct Point start = { 0, 0 };
			struct Point dest = { 4, 4 };

			struct Route result = shortestPath(&map, start, dest);

			//check route is not null
			Assert::IsNotNull(&result.routeSymbol, L"The route symbol should not be null");

			//check num of point > 0 
			Assert::IsTrue(result.numPoints > 0, L"There should be at least one point in the route");

			//check row, col point is not null
			Assert::IsNotNull(&result.points[0].row, L"The route row point should not be null");
			Assert::IsNotNull(&result.points[0].col, L"The route col point should not be null");
		}

		TEST_METHOD(STF_TestMethod3)
		{
			Logger::WriteMessage("is it pointing shotest path testcases?");

			struct Map map = { 0 };
			map.numRows = 5;
			map.numCols = 5;

			struct Point start = { 2, 2 };
			struct Point dest = { 2, 2 };

			struct Route result = shortestPath(&map, start, dest);

			//check route is not null
			Assert::IsNotNull(&result.routeSymbol, L"The route symbol should not be null");

			//check num of point > 0 
			Assert::IsFalse(result.numPoints > 0, L"There should be at least one point in the route");

			//check row, col point is not null
			Assert::IsNotNull(&result.points[0].row, L"The route row point should not be null");
			Assert::IsNotNull(&result.points[0].col, L"The route col point should not be null");
		}

		TEST_METHOD(STF_TestMethod4)
		{
			Logger::WriteMessage("is it pointing shotest path testcases?");

			struct Map* map = nullptr;

			struct Point start = { 0, 0 };
			struct Point dest = { 4, 4 };

			struct Route result = shortestPath(map, start, dest);

			//check route is not null
			Assert::IsNotNull(&result.routeSymbol, L"The route symbol should not be null");

			//check num of point > 0 
			Assert::IsFalse(result.numPoints > 0, L"There should be at least one point in the route");

			//check row, col point is not null
			Assert::IsNotNull(&result.points[0].row, L"The route row point should not be null");
			Assert::IsNotNull(&result.points[0].col, L"The route col point should not be null");
		}
	};
	//testing valid box size, Function : checkSize
	TEST_CLASS(testboxsize)
	{
	public:
		TEST_CLASS_INITIALIZE(ClassInitialize)
		{
			Logger::WriteMessage("In Class Initialize");
		}

		TEST_CLASS_CLEANUP(ClassCleanup)
		{
			Logger::WriteMessage("In Class Cleanup");
		}

		// exactly same with small_size
		TEST_METHOD(CST_TestMethod1)
		{
			Logger::WriteMessage("Is the entered argument value a valid size?");

			int result = checkSize(0.25);
			Assert::AreEqual(1, result);
		}
		// exactly same with medium_size
		TEST_METHOD(CST_TestMethod2)
		{
			Logger::WriteMessage("Is the entered argument value a valid size?");

			int result = checkSize(0.5);
			Assert::AreEqual(1, result);
		}
		// exactly same with large_size
		TEST_METHOD(CST_TestMethod3)
		{
			Logger::WriteMessage("Is the entered argument value a valid size?");

			int result = checkSize(1);
			Assert::AreEqual(1, result);
		}
		// 0 value in size parameter
		TEST_METHOD(CST_TestMethod4)
		{
			Logger::WriteMessage("Is the entered argument value a valid size?");

			int result = checkSize(0);
			Assert::AreEqual(0, result);
		}
		// NULL has been inserted
		TEST_METHOD(CST_TestMethod5)
		{
			Logger::WriteMessage("Is the entered argument value a valid size?");

			int result = checkSize(NULL);
			Assert::AreEqual(0, result);
		}
		// char type value has been inserted : program termination
		/*TEST_METHOD(CST_TestMethod6)
		{
			Logger::WriteMessage("Is the entered argument value a valid size?");

			int result = checkSize("abc/#&$");
			Assert::AreEqual(0, result);
		}*/
	};

	//testing vaild map spot, Function : checkPoint
	TEST_CLASS(testmappoint)
	{
	public:
		TEST_CLASS_INITIALIZE(ClassInitialize)
		{
			Logger::WriteMessage("In Class Initialize");
		}

		TEST_CLASS_CLEANUP(ClassCleanup)
		{
			Logger::WriteMessage("In Class Cleanup");
		}

		// both col, row are between 0~25
		TEST_METHOD(CMS_TestMethod1)
		{
			Logger::WriteMessage("Is the entered argument pointing valid spot?");

			int result = checkPoint({ 10, 10 });
			Assert::AreEqual(1, result);
		}
		// only row is out of range
		TEST_METHOD(CMS_TestMethod2)
		{
			Logger::WriteMessage("Is the entered argument pointing valid spot?");

			int result = checkPoint({ -1, 20 });
			Assert::AreEqual(0, result);
		}
		//  only col is out of range
		TEST_METHOD(CMS_TestMethod3)
		{
			Logger::WriteMessage("Is the entered argument pointing valid spot?");

			int result = checkPoint({ 20, -1 });
			Assert::AreEqual(0, result);
		}
		// 0 in one of value, to check location is start from 0 or not
		TEST_METHOD(CMS_TestMethod4)
		{
			Logger::WriteMessage("Is the entered argument pointing valid spot?");

			int result = checkPoint({ 0, 25 });
			Assert::AreEqual(0, result);
		}
		// Only one value has inserted
		TEST_METHOD(CMS_TestMethod5)
		{
			Logger::WriteMessage("Is the entered argument pointing valid spot?");

			int result = checkPoint({ 10 });
			Assert::AreEqual(1, result);
		}
		// invalid value special char input : program termination
		/*TEST_METHOD(CMS_TestMethod5)
		{
			Logger::WriteMessage("Is the entered argument pointing valid spot?");

			int result = checkPoint({ "@$*#@",10 });
			Assert::AreEqual(0, result);
		}*/
	};

	//testing size,weight and accepted point, Function : checkAll
	//couldn't get 0 when we dont know default one
	TEST_CLASS(testallinput)
	{
	public:
		TEST_CLASS_INITIALIZE(ClassInitialize)
		{
			Logger::WriteMessage("In Class Initialize");
		}

		TEST_CLASS_CLEANUP(ClassCleanup)
		{
			Logger::WriteMessage("In Class Cleanup");
		}

		// size value is smaller than minimum
		TEST_METHOD(APT_TestMethod1)
		{
			Logger::WriteMessage("Is the entered arguments are all passing validation?");
			Point pt;
			pt.row = 2;
			pt.col = 2;
			int result = checkAll(0, 1, pt);
			Assert::AreEqual(-1, result);
		}
		// weight value is smaller than minimum
		TEST_METHOD(APT_TestMethod2)
		{
			Logger::WriteMessage("Is the entered arguments are all passing validation?");

			int result = checkAll(1, 0, { 2, 2 });
			Assert::AreEqual(-2, result);
		}
		// point value is not on the range
		TEST_METHOD(APT_TestMethod3)
		{
			Logger::WriteMessage("Is the entered arguments are all passing validation?");

			int result = checkAll(1, 1, { 26, 3 });
			Assert::AreEqual(-3, result);
		}
		// All valid values but couldnt pass blocked space
		TEST_METHOD(APT_TestMethod4)
		{
			Logger::WriteMessage("Is the entered arguments are all passing validation?");

			int result = checkAll(0.5, 1500, { 24, 24 });
			Assert::AreEqual(-3, result);
		}
		// size exceed maximum
		TEST_METHOD(APT_TestMethod5)
		{
			Logger::WriteMessage("Is the entered arguments are all passing validation?");

			int result = checkAll(2, 1500, {25, 25});
			Assert::AreEqual(-1, result);
		}
		// weight exceed maximum
		TEST_METHOD(APT_TestMethod6)
		{
			Logger::WriteMessage("Is the entered arguments are all passing validation?");

			int result = checkAll(0.5, 1501, { 25, 25 });
			Assert::AreEqual(-2, result);
		}
		// invalid value (char) inserted on weight : intentionally causing error
		/*TEST_METHOD(APT_TestMethod7)
		{
			Logger::WriteMessage("Is the entered arguments are all passing validation?");

			int result = checkAll(38, "abc", { 25,25 });
			Assert::AreEqual(0, result);
		}*/
		// no point value
		TEST_METHOD(APT_TestMethod8)
		{
			Logger::WriteMessage("Is the entered arguments are all passing validation?");

			int result = checkAll(1, 1501, { });
			Assert::AreEqual(-2, result);
		}
	};


	// check if row num has accurately returned, Function : eqPt
	TEST_CLASS(testequalpointer)
	{
	public:
		TEST_CLASS_INITIALIZE(ClassInitialize)
		{
			Logger::WriteMessage("In Class Initialize");
		}

		TEST_CLASS_CLEANUP(ClassCleanup)
		{
			Logger::WriteMessage("In Class Cleanup");
		}

		// valid spot and matched values
		TEST_METHOD(TNR_TestMethod1)
		{
			Logger::WriteMessage("check if two point has been matched?");

			int result = eqPt({ 10,10 }, { 10,10 });
			Assert::AreEqual(1, result);
		}
		// invalid point but matcher
		TEST_METHOD(TEP_TestMethod2)
		{
			Logger::WriteMessage("check if two point has been matched?");

			int result = eqPt({ 10,30 }, { 10,30 });
			Assert::AreEqual(1, result);
		}
		// both doesnt match
		TEST_METHOD(TEP_TestMethod3)
		{
			Logger::WriteMessage("check if two point has been matched?");

			int result = eqPt({ 0,-1 }, { 10,12 });
			Assert::AreEqual(0, result);
		}
		// only one matches
		TEST_METHOD(TEP_TestMethod4)
		{
			Logger::WriteMessage("check if two point has been matched?");

			int result = eqPt({ 0,1 }, { 0,2 });
			Assert::AreEqual(0, result);
		}
		// uncompleted input
		TEST_METHOD(TEP_TestMethod5)
		{
			Logger::WriteMessage("check if two point has been matched?");

			int result = eqPt({ 10,15 }, { 10 });
			Assert::AreEqual(0, result);
		}
		// different type of input : intentionally check compiler error
		/*TEST_METHOD(TEP_TestMethod6)
		{
			Logger::WriteMessage("check if two point has been matched?");

			int result = eqPt({ 10,15 }, { "abc",12 });
			Assert::AreEqual(0, result);
		}*/
	};

	// check if row num has accurately returned, Function : getNumRows => out of expectation, recieved values are changed
	// case fixed after fixing code
	TEST_CLASS(testrownum)
	{
	public:
		TEST_CLASS_INITIALIZE(ClassInitialize)
		{
			Logger::WriteMessage("In Class Initialize");
		}

		TEST_CLASS_CLEANUP(ClassCleanup)
		{
			Logger::WriteMessage("In Class Cleanup");
		}

		// no value inserted
		TEST_METHOD(TNR_TestMethod1)
		{
			Logger::WriteMessage(" row which is pased matched with num?");

			struct Map* map = nullptr;

			int result = getNumRows(map);

			Assert::AreEqual(0, result); 
		}
		// row value 1 has passed
		TEST_METHOD(TNR_TestMethod2)
		{
			Logger::WriteMessage(" row which is pased matched with num?");

			struct Map map = { 0 };
			map.numRows = 1;
			map.numCols = 2;

			int result = getNumRows(&map);

			Assert::AreEqual(1, result);
		}
		//  rAll value passing max
		TEST_METHOD(TNR_TestMethod3)
		{
			Logger::WriteMessage(" row which is pased matched with num?");

			struct Map map = { 0 };
			map.numRows = MAP_ROWS;
			map.numCols = MAP_COLS;

			int result = getNumRows(&map);

			Assert::AreEqual(25, result);
		}
		//  row value 3 has passed => wrong expectation case (not accepting multi Array
		/*TEST_METHOD(TNR_TestMethod4)
		{
			Logger::WriteMessage(" row which is passed matched with num?");

			int result = getNumRows({ 0， 0 }，{ 1， 1 }，{0, 1}, 3， 2);
			Assert::AreEqual(3, result);
		}
		//  map num and row num hasnt matched => wrong expectation case2(not accepting multi Array)
		TEST_METHOD(TNR_TestMethod5)
		{
			Logger::WriteMessage(" row which is passed matched with num?");

			int result = getNumRows({ 0， 0 }，{ 1， 1 }，{0, 1}, 5， 2);
			Assert::AreEqual(3, result);
		}*/
		//  not null but empty 
		TEST_METHOD(TNR_TestMethod6)
		{
			Logger::WriteMessage(" row which is pased matched with num?");

			struct Map map = { };
			map.numRows = 0;
			map.numCols = 0;

			int result = getNumRows(&map);

			Assert::AreEqual(0, result);
		}
	};

	// check if row num has accurately returned, Function : onTheRoute  => out of expectation, recieved values are changed
	// case fixed after fixing code, couldnt test with assertion

	/*TEST_CLASS(testroutevalid)
	{
	public:
		TEST_CLASS_INITIALIZE(ClassInitialize)
		{
			Logger::WriteMessage("In Class Initialize");
		}

		TEST_CLASS_CLEANUP(ClassCleanup)
		{
			Logger::WriteMessage("In Class Cleanup");
		}

		// are not in any points
		TEST_METHOD(TRV_TestMethod1)
		{
			Logger::WriteMessage("is destination on valid route?");

			int result = onTheRoute({ 1， 0 }，{ 2， 0 }，{ 3， 0 }，{ 4， 0 }， 4， { 300, 40, { 12, 0 } });
			Assert::AreEqual(0, result);
		}
		// passing route with spot cols ->0
		TEST_METHOD(TRV_TestMethod2)
		{
			Logger::WriteMessage("is destination on valid route?");

			int result = onTheRoute({ 1， 0 }，{ 2， 0 }，{ 3， 0 }，{ 4， 0 }， 4， { 300, 40, { 4, 0 } });
			Assert::AreEqual(1, result);
		}
		// case if numPoint doesnt matches, and matched index are bigger than it
		TEST_METHOD(TRV_TestMethod3)
		{
			Logger::WriteMessage("is destination on valid route");

			int result = onTheRoute({ 1， 0 }，{ 2， 0 }，{ 3， 0 }，{ 4， 0 }，{ 5， 0 }，{ 5， 1 }，{ 5， 2 }， 5， { 300, 40, { 5, 2 } });
			Assert::AreEqual(0, result);
		}
		// Index matched but not int type
		TEST_METHOD(TRV_TestMethod4)
		{
			Logger::WriteMessage("is destination on valid route");

			int result = onTheRoute({ "a"， "b" }，{ 2， 0 }，{ 3， 0 }，{ 4， 0 }，{ 5， 0 }，{ 5， 1 }，{ 5， 2 }， 5， { 300, 40, { "a"， "b" } });
			Assert::AreEqual(0, result);
		}
		// case if numPoint is char type
		TEST_METHOD(TRV_TestMethod3)
		{
			Logger::WriteMessage("is destination on valid route");

			int result = onTheRoute({ 1， 0 }，{ 2， 0 }，{ 3， 0 }，{ 4， 0 }，{ 5， 0 }，{ 5， 1 }，{ 5， 2 }， "hello"， { 300, 40, { 1, 0 } });
			Assert::AreEqual(0, result);
		}
	};*/

	
	

	// check the best route between available posit, Function : compareTruck
	/* : couldn't test these two functions with assert: need console to test
	TEST_CLASS(testoccupyingless)
	{
	public:
		TEST_CLASS_INITIALIZE(ClassInitialize)
		{
			Logger::WriteMessage("In Class Initialize");
		}

		TEST_CLASS_CLEANUP(ClassCleanup)
		{
			Logger::WriteMessage("In Class Cleanup");
		}

		// no value of each in truck B
		TEST_METHOD(TOL_TestMethod1)
		{
			Logger::WriteMessage("is destination on pointing best route?");

			int result = chooseTruck({}, { {{1,1}, {1,2}, {1,3}},{1, 4}, {1, 5} , 5, 'C' }, 600, 10});
			Assert::AreEqual("B", result);
	    }
	    // Case Truck B's weight and volume all smaller than C
	    TEST_METHOD(TOL_TestMethod2)
	    {
		   Logger::WriteMessage("is destination on pointing best route?");

		   int result = chooseTruck({ {{1,1}, {2,1}, {3,1}}, 3, 'B' }, 200, 6.5}, { {{1,1}, {1,2}, {1,3}},{1, 4}, {1, 5} , 5, 'C' }, 600, 10}});
		   Assert::AreEqual("B", result);
	    }
		// For weight C is heavier but for volumn B is more
		TEST_METHOD(TOL_TestMethod3)
		{
			Logger::WriteMessage("is destination on pointing best route?");

			int result = chooseTruck({ {{1,1}, {2,1}, {3,1}}, 3, 'B' }, 600, 36}, { {{1,1}, {1,2}, {1,3}},{1, 4}, {1, 5} , 5, 'C' }, 0, 0});
			Assert::AreEqual("C", result);
		}
		//  Same Occupy rate but different num
		TEST_METHOD(TOL_TestMethod4)
		{
			Logger::WriteMessage("is destination on pointing best route?");

			int result = chooseTruck({ {{1,1}, {2,1}, {3,1}}, 3, 'B' }, 0, 0}, { {{1,1}, {1,2}, {1,3}},{1, 4}, {1, 5} , 5, 'C' }, 0, 0});
			Assert::AreEqual("B", result);
		}
		//  double type num vut in range
		TEST_METHOD(TOL_TestMethod5)
		{
			Logger::WriteMessage("is destination on pointing best route?");

			int result = chooseTruck({ {{1,1}, {2,1}, {3,1}}, 3, 'B' }, 50, 18}, { {{1,1}, {1,2}, {1,3}},{1, 4}, {1, 5} , 5, 'C' }, 500, 3.6});
			Assert::AreEqual("B", result);
		}
		// case if symbol empty or an space type escape sequence => error case
       TEST_METHOD(TOL_TestMethod6)
		{
			Logger::WriteMessage("is destination on pointing best route?");

			int result = chooseTruck({ {{1,1}, {2,1}, {3,1}}, 3, ' ' }, 0, 0}, { {{1,1}, {1,2}, {1,3}},{1, 4}, {1, 5} , 5, '\t' }, 0, 0});
			Assert::AreEqual(" ", result);
		}
	};
	// comparing two truck as size and weight, Function : compareTruck
	TEST_CLASS(testoccupyingless)
	{
	public:
		TEST_CLASS_INITIALIZE(ClassInitialize)
		{
			Logger::WriteMessage("In Class Initialize");
		}

		TEST_CLASS_CLEANUP(ClassCleanup)
		{
			Logger::WriteMessage("In Class Cleanup");
		}

		// no value of each in truck B => error case
		TEST_METHOD(TOL_TestMethod1)
		{
			Logger::WriteMessage("which one is more effiecient?");

			int result = chooseTruck({}, { {{1,1}, {1,2}, {1,3}},{1, 4}, {1, 5} , 5, 'C' }, 600, 10});
			Assert::AreEqual("B", result);
		}
		// Case Truck B's weight and volume all smaller than C
		TEST_METHOD(TOL_TestMethod2)
		{
			Logger::WriteMessage(" which one is more effiecient?");
			struct Truck tk1, tk2;
			tk1 = { {1,1}, {2,1}, {3,1} }, 3, 'B'}, 200, 6.5};
	        tk2 = { {{1,1}, {1,2}, {1,3}},{1, 4}, {1, 5} , 5, 'C' }, 600, 10};

		   char result = chooseTruck(&tk1,&tk2);
		   Assert::AreEqual('B',result);
		}
		// For weight C is heavier but for volumn B is more
		TEST_METHOD(TOL_TestMethod3)
		{
			Logger::WriteMessage("which one is more effiecient");

			int result = chooseTruck({ {{1,1}, {2,1}, {3,1}}, 3, 'B' }, 600, 36}, { {{1,1}, {1,2}, {1,3}},{1, 4}, {1, 5} , 5, 'C' }, 0, 0});
			Assert::AreEqual("C", result);
		}
		//  Same Occupy rate but different num
		TEST_METHOD(TOL_TestMethod4)
		{
			Logger::WriteMessage("which one is more effiecient");

			int result = chooseTruck({ {{1,1}, {2,1}, {3,1}}, 3, 'B' }, 0, 0
		}, { {{1,1}, {1,2}, {1,3}},{1, 4}, {1, 5} , 5, 'C' }, 0, 0});
			Assert::AreEqual("B", result);
		}
		//  double type num vut in range
		TEST_METHOD(TOL_TestMethod5)
		{
			Logger::WriteMessage("which one is more effiecient?");

			int result = chooseTruck({ {{1,1}, {2,1}, {3,1}}, 3, 'B' }, 50, 18}, { {{1,1}, {1,2}, {1,3}},{1, 4}, {1, 5} , 5, 'C' }, 500, 3.6});
			Assert::AreEqual("B", result);
		}
		// case if symbol empty or an space type escape sequence
		TEST_METHOD(TOL_TestMethod6)
		{
			Logger::WriteMessage("which one is more effiecient");

			int result = chooseTruck({ {{1,1}, {2,1}, {3,1}}, 3, ' ' }, 0, 0
		}, { {{1,1}, {1,2}, {1,3}},{1, 4}, {1, 5} , 5, '\t' }, 0, 0});
			Assert::AreEqual(" ", result);
		}
	};*/
	//testing percent calculation, Function : calculatePercent
	TEST_CLASS(testcalpercent)
	{
	public:
		TEST_CLASS_INITIALIZE(ClassInitialize)
		{
			Logger::WriteMessage("In Class Initialize");
		}

		TEST_CLASS_CLEANUP(ClassCleanup)
		{
			Logger::WriteMessage("In Class Cleanup");
		}
		// 1~7 blackbox, think opposite => AreNotEqual
		// 8~11 Whitebox, Are equal
		// all input and outputs are matched type
		TEST_METHOD(TCP_TestMethod1)
		{
			Logger::WriteMessage("testing calculation correct?");

			double result = calculatePercent(10, 20);
			Assert::AreNotEqual(0.50, result);
		}
		// case value is 0 
		TEST_METHOD(TCP_TestMethod2)
		{
			Logger::WriteMessage("testing calculation correct?");

			double result = calculatePercent(0, 1500);
			Assert::AreNotEqual(0.00, result);
		}
		// case value isnt invalid type (char) => error case
		/*TEST_METHOD(TCP_TestMethod3)
		{
			Logger::WriteMessage("testing calculation correct?");

			double result = calculatePercent("abcd", 1500);
			result = static_cast<int>(result);
			Assert::AreEqual(-1, result);
		}*/
		// when the value on "val" is double not integer as pre declared
		TEST_METHOD(TCP_TestMethod4)
		{
			Logger::WriteMessage("testing calculation correct?");

			double result = calculatePercent(1500.25, 1500);
			Assert::AreNotEqual(1.00, result);
		}
		// when one argument is missing => error case parameter unmatched
		/*TEST_METHOD(TCP_TestMethod5)
		{
			Logger::WriteMessage("testing calculation correct?");

			int result = calculatePercent(100);
			Assert::AreEqual(-1, result);
		}*/
		// when max(base dividing num) is 0 which means infinity
		TEST_METHOD(TCP_TestMethod6)
		{
			Logger::WriteMessage("testing calculation correct?");

			double result = calculatePercent(1, 0);

			// Assuming calculatePercent returns positive infinity for division by zero
			Assert::IsTrue(std::isinf(result) && result > 0);
		}
		// case when it's negative value
		TEST_METHOD(TCP_TestMethod7)
		{
			Logger::WriteMessage("testing calculation correct?");

			double result = calculatePercent(-500, 1500);
			Assert::AreNotEqual(-0.33, result);
		}
		//whitebox 
		TEST_METHOD(TCP_TestMethod8)
		{
			Logger::WriteMessage("testing calculation correct?");

			double result = calculatePercent(10, 2000);
			Assert::AreEqual(0.5, result);
		}
		// case value is doubletype as a calculation
		TEST_METHOD(TCP_TestMethod9)
		{
			Logger::WriteMessage("testing calculation correct?");

			double result = calculatePercent(1500.25, 1500);
			Assert::AreEqual(100.00, result);
		}
		//case negative
		TEST_METHOD(TCP_TestMethod10)
		{
			Logger::WriteMessage("testing calculation correct?");

			double result = calculatePercent(-5, 15);
			Assert::AreEqual(-33.3333, result);
		}
	};

	//testing finding truck, Function : findTruck
	// => function using console so couldnt test directly, can solve with integration test(which will be mentioned in document)
	TEST_CLASS(testmatchtruck)
	{
	public:
		TEST_CLASS_INITIALIZE(ClassInitialize)
		{
			Logger::WriteMessage("In Class Initialize");
		}

		TEST_CLASS_CLEANUP(ClassCleanup)
		{
			Logger::WriteMessage("In Class Cleanup");
		}

		// all input and outputs are matched type, and matched in truck A
		TEST_METHOD(TMT_TestMethod1)
		{
			Logger::WriteMessage("inputs are valid and truck has matched");

			struct Delivery ship = { 200, 18, { 12,5 } };

			int result = findTruck(ship);
			Assert::AreNotEqual(2, result);
		}
		// All matched to A but invalid adress spot
		TEST_METHOD(TMT_TestMethod2)
		{
			Logger::WriteMessage("inputs are valid and truck has matched");
			struct Delivery ship = { 200, 18, { 28,4 } };
			int result = findTruck(ship);
			Assert::AreEqual(-1, result);
		}
		// case  isnt invalid type (char) => error case no type matched
		/*
		TEST_METHOD(TMT_TestMethod3)
		{
			Logger::WriteMessage("inputs are valid and truck has matched");

			int result = findTruck(200, "abc", { 12,5 });
			Assert::AreEqual(-1, result);
		}*/
		// when the value on "val" is double not integer as pre declared but narrowed so case B matched
		TEST_METHOD(TMT_TestMethod4)
		{
			Logger::WriteMessage("inputs are valid and truck has matched");
			struct Delivery ship = { 200, 0, { 12,5 } };
			int result = findTruck(ship);
			Assert::AreNotEqual(4, result);
		}
		// intentionally causing overflow
		TEST_METHOD(TMT_TestMethod5)
		{
			Logger::WriteMessage("inputs are valid and truck has matched");

			struct Delivery ship = { 2147483648, 18, { 12,5 } };
			int result = findTruck(ship);
			Assert::AreEqual(8, result);
		}
		// height exceed the value but matched to truck B
		TEST_METHOD(TMT_TestMethod6)
		{
			Logger::WriteMessage("inputs are valid and truck has matched");

			struct Delivery ship = { 100, 9, { 22,2 } };
			int result = findTruck(ship);
			Assert::AreEqual(-1, result);
		}
		// Empty ship => error case
		/*
		TEST_METHOD(TMT_TestMethod7)
		{
			Logger::WriteMessage("inputs are valid and truck has matched");

			int result = calculatePercent(200, 18, {});
			Assert::AreEqual(-0.33, result);
		}*/
	};

	
	//testing func : AddpointToRoute
	TEST_CLASS(AddPointRoute)
	{
	public:
		TEST_CLASS_INITIALIZE(ClassInitialize)
		{
			Logger::WriteMessage("In Class Initialize");
		}

		TEST_CLASS_CLEANUP(ClassCleanup)
		{
			Logger::WriteMessage("In Class Cleanup");
		}

		TEST_METHOD(APR_Testcase1)
		{
			Logger::WriteMessage("NO Error, Matched Point included to Route");

			struct Route route = { 0 };
			route.numPoints = 0; // Ensure the route is initially empty

			addPointToRoute(&route, 3, 4);

			Assert::AreEqual(static_cast<int>(3), static_cast<int>(route.points[0].row));
			Assert::AreEqual(static_cast<int>(4), static_cast<int>(route.points[0].col));
		}

		TEST_METHOD(APR_Testcase2)
		{
			Logger::WriteMessage("NO Error, Matched Point included to Route");

			struct Route route = { 0 };
			route.numPoints = 0;

			// Add a point
			addPointToRoute(&route, 3, 4);

			// Try to add the same point again
			Assert::Fail;
		}

		TEST_METHOD(APR_Testcase3)
		{
			Logger::WriteMessage("NO Error, Matched Point included to Route");

			struct Route route = { 0 };
			route.numPoints = 0;

			addPointToRoute(&route, 3, 4);

			Assert::AreEqual(static_cast<int>(3), static_cast<int>(route.points[0].row));
			Assert::AreEqual(static_cast<int>(4), static_cast<int>(route.points[0].col));
		}

		TEST_METHOD(APR_Testcase4)
		{
			Logger::WriteMessage("NO Error, Matched Point included to Route");

			struct Route* route = nullptr;

			// case if point is nullptr
			Assert::ExpectException<std::invalid_argument>([&]() { addPointToRoute(route, 3, 4); });
		}

		TEST_METHOD(APR_Testcase5)
		{
			Logger::WriteMessage("NO Error, Matched Point included to Route");

			struct Route route = { 0 };
			route.numPoints = 0;

			// case if point Max
			addPointToRoute(&route, CHAR_MAX, CHAR_MAX);

			Assert::AreEqual(static_cast<int>(CHAR_MAX), static_cast<int>(route.points[0].row));
			Assert::AreEqual(static_cast<int>(CHAR_MAX), static_cast<int>(route.points[0].col));
		}
	};

	// check the best route between available posit, Function : findBestRoute
	// function3 , that couldnt be tested by assertion needs console 
	/*TEST_CLASS(testbestroutevalid)
	{
	public:
		TEST_CLASS_INITIALIZE(ClassInitialize)
		{
			Logger::WriteMessage("In Class Initialize");
		}

		TEST_CLASS_CLEANUP(ClassCleanup)
		{
			Logger::WriteMessage("In Class Cleanup");
		}

		TEST_METHOD(BRV_TestMethod1)
		{
			Logger::WriteMessage("is destination on pointing best route?");

			// Assume findBestRoute function takes appropriate arguments
			int result = findBestRoute({}, 0, { 200, 5.0, {4, 5} });
			Assert::AreEqual(-1, result);
		}

		TEST_METHOD(BRV_TestMethod2)
		{
			Logger::WriteMessage("is destination on pointing best route?");

			// Assume findBestRoute function takes appropriate arguments
			int result = findBestRoute({ { {1, 1}, {2, 2}, {3, 3} }, 3, 'B' }, 1, { 200, 5.0, { 3, 3 } });
			Assert::AreEqual(0, result);
		}

		TEST_METHOD(BRV_TestMethod3)
		{
			Logger::WriteMessage("is destination on pointing best route?");

			// Assume findBestRoute function takes appropriate arguments
			int result = findBestRoute({ { {1, 1}, {1, 2}, {1, 3}, {1, 4} }, 4, 'B' }, { {1, 1}, {2, 2}, {3, 3}, {3, 4}, {4, 4} }, 4, 'C', 2, { 200, 5.0, {3, 3} });
			Assert::AreEqual(1, result);
		}
			// when the identifiers are empty or escape sequence : error case (generated)
			TEST_METHOD(BRV_TestMethod4)
			{
				Logger::WriteMessage("is destination on pointing best route?");

				int result = findBestRoute({ {{1,1}, {1, 2}, {1,3}, {1, 4}}, 4, ' ' }, { {1,1}, {2,2}, {3,3}, {3, 4}, {4, 4} }, 4, '\n'
					2, { 200, 5.0, {3, 3} });
				Assert::AreEqual(1, result);
			}

			//  If number of pointer doenst matched
			TEST_METHOD(BRV_TestMethod5)
			{
				Logger::WriteMessage("is destination on pointing best route?");

				int result = findBestRoute({ {{1,1}, {1, 2}, {1,3}, {1, 4}}, 3, 'B' }, { {1,1}, {2,2}, {3,3}, {3, 4}, {4, 4} }, 2, 'C', 2, { 200, 5.0, {3, 3} });
				Assert::AreEqual(-1, result);
			}
			//  If number of pointer invalid (char)type
			TEST_METHOD(BRV_TestMethod6)
			{
				Logger::WriteMessage("is destination on pointing best route?");

				int result = findBestRoute({ {{1,1}, {1, 2}, {1,3}, {1, 4}}, 4, 'B' }, { {1,1}, {2,2}, {3,3}, {3, 4}, {4, 4} }, "m", 'C', 2, { 200, 5.0, {3, 3} });
				Assert::AreEqual(-1, result);
			}
	};*/
}