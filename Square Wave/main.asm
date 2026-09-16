ORG 0000H

MOV TMOD, #10H

NXT: MOV TL1, #8FH
     MOV TH1, #0D8H

     SETB TR1

WAIT: JNB TF1, WAIT

     CLR TR1
     CPL P2.1
     CLR TF1

     SJMP NXT

END