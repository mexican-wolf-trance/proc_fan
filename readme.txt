Here it begins!

This program creates a process fan by redirecting a file called testing.data into the proc_fan program. Testing.data contains ten iterations of the "testsim" program. This program simply waits for the amount of seconds passed and kills itself. The proc_fan takes in a -n argument followed by the number of processes to execute at once. For example: proc_fan -n 5 < testing.data.

FOR FUTURE REFERENCE: You need to add the ./ in the testin.data programs OR IT DOESN'T WORK. Now we all know and we won't make the same mistake again and waste hours of our lives.

Note: I wasn't sure how to get the parent to wait for all the children to finish before the next fan begins. As it stands, it starts the number requested children, and then when one finishes, the next one starts one at a time. 
