phpcs:set WordPress.WhiteSpace.PrecisionAlignment ignoreAlignmentTokens[] T_COMMENT,T_DOC_COMMENT_WHITESPACE,T_INLINE_HTML,T_FUNCTION

<?php

	function exampleFunctionA() {} // OK: [tab].

/*
 * OK: [tab][space][space][space][space].
 * The four spaces will be replaced by a tab by the upstream sniff.
 */
	    function exampleFunctionB() {}

/*
 * OK: [tab][space][space][tab][space][tab].
 * The space replacement here will be handled by the upstream sniff.
 */
	  	 	function exampleFunctionC() {}

	/**
	 * OK: Doc comments are indented with tabs and one space.
	 *
	  * @var string  <= Bad, but not reported as token type is ignored.
	 * @access private
	 */

	/*
	 * OK: Multi-line comments are indented with tabs and one space.
	 *
	   * <= Bad, but not reported as token type is ignored
	 */

	 function exampleFunctionD() {} // Bad, but not reported as token type is ignored.
	  function exampleFunctionE() {} // Bad, but not reported as token type is ignored.
	   function exampleFunctionF() {} // Bad, but not reported as token type is ignored.

?>

	<p>
	  Bad: Some text with precision alignment, but not reported as token type is ignored.
	</p>

<?php

// phpcs:set WordPress.WhiteSpace.PrecisionAlignment ignoreAlignmentTokens[]
