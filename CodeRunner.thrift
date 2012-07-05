

struct CodePizza {
    1: string lanuage,
    2: string os,
    3: string code,
    4: string stdin 
}

struct RunResult {
	1: i32	  ret,
        2: i32    cacheHit,
	3: string stdin,
	4: string stdout,
	5: string stderr,
	6: i32 userid,
	7: i32 realExecTime,
	8: i32 timestamp
}


service CodeRunner {

	/**
	 * 执行一段代码.
	 */
	RunResult run(1: CodePizza pizza, 2: i32 userid);

        CodePizza format(1:CodePizza pizza);
}

