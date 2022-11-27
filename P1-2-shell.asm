https://powcoder.com
代写代考加微信 powcoder
Assignment Project Exam Help
Add WeChat powcoder
https://powcoder.com
代写代考加微信 powcoder
Assignment Project Exam Help
Add WeChat powcoder

# P1-2
# Student Name:
# Date:
#
# This program solves a match puzzle.

.data
Reference:   .alloc 1				# allocate space for reference pattern
Candidates:  .alloc 8				# allocate space for puzzle candidates

.text
MPuzzle:	addi	$1, $0, Reference	# set memory base
		swi	582			# create and display puzzle

# your code goes here ...

		addi	$3, $0, 28		# guess puzzle offset 28
		swi	583			# highlight and report match
		jr      $31			# return to operating system

