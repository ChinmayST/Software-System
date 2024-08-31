/*
============================================================================
Name : 2.c
Author : Chinmay Tavarej
Description : Write a simple program to execute in an infinite loop at the background. Go to /proc directory and
	identify all the process related information in the corresponding proc directory
Date: 10th Aug, 2024.
============================================================================
*/
#include<stdio.h>
int main(){
	for(;;){
		printf("a\n");
	}
	return 0;
}
/*
 Input and Output:
Input:
iiitb@iiitb-Dell-G15-5511:~/Downloads/system-programming-codes-main/2$ ps aux | grep infin_prog
iiitb      12808 87.6  0.0   2616  1024 pts/3    R    16:59   0:18 ./infin_prog
iiitb      12824  0.0  0.0   9204  2432 pts/4    S+   16:59   0:00 grep --color=auto infin_prog
iiitb@iiitb-Dell-G15-5511:~/Downloads/system-programming-codes-main/2$ cat /proc/12808/status

Output : 
Name:	infin_prog
Umask:	0002
State:	R (running)
Tgid:	12808
Ngid:	0
Pid:	12808
PPid:	12743
TracerPid:	0
Uid:	1000	1000	1000	1000
Gid:	1000	1000	1000	1000
FDSize:	256
Groups:	4 24 27 30 46 100 118 1000 
NStgid:	12808
NSpid:	12808
NSpgid:	12808
NSsid:	12743
VmPeak:	    2616 kB
VmSize:	    2616 kB
VmLck:	       0 kB
VmPin:	       0 kB
VmHWM:	    1024 kB
VmRSS:	    1024 kB
RssAnon:	       0 kB
RssFile:	    1024 kB
RssShmem:	       0 kB
VmData:	     224 kB
VmStk:	     132 kB
VmExe:	       4 kB
VmLib:	    1672 kB
VmPTE:	      40 kB
VmSwap:	       0 kB
HugetlbPages:	       0 kB
CoreDumping:	0
THP_enabled:	1
Threads:	1
SigQ:	0/62488
SigPnd:	0000000000000000
ShdPnd:	0000000000000000
SigBlk:	0000000000000000
SigIgn:	0000000000000000
SigCgt:	0000000000000000
CapInh:	0000000000000000
CapPrm:	0000000000000000
CapEff:	0000000000000000
CapBnd:	000001ffffffffff
CapAmb:	0000000000000000
NoNewPrivs:	0
Seccomp:	0
Seccomp_filters:	0
Speculation_Store_Bypass:	thread vulnerable
SpeculationIndirectBranch:	conditional enabled
Cpus_allowed:	fff
Cpus_allowed_list:	0-11
Mems_allowed:	00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000001
Mems_allowed_list:	0
voluntary_ctxt_switches:	816
nonvoluntary_ctxt_switches:	196

Threads:	2
SigQ:	1/30554
SigPnd:	0000000000000000
ShdPnd:	0000000000000000
SigBlk:	0000000000000000
SigIgn:	0000000000003000
SigCgt:	000000016f8a4eff
CapInh:	0000000000000000
CapPrm:	0000000000000000
CapEff:	0000000000000000
CapBnd:	000001ffffffffff
CapAmb:	0000000000000000
NoNewPrivs:	0
Seccomp:	0
Seccomp_filters:	0
Speculation_Store_Bypass:	thread vulnerable
SpeculationIndirectBranch:	conditional enabled
Cpus_allowed:	ff
Cpus_allowed_list:	0-7
Mems_allowed:	00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000001
Mems_allowed_list:	0
voluntary_ctxt_switches:	92
nonvoluntary_ctxt_switches:	2
 */
