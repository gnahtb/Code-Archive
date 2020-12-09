uses math;
const fi='inp.txt';
      fo='out.txt';
var a,b,c,d,i,t1,t2,rslt:longint;
begin
        //assign(input,fi); reset(input);
        //assign(output,fo); rewrite(output);
        readln(a,b);
        readln(c,d);
        rslt:=-1;
        for i:=0 to max(a,max(b,max(c,d))) do
                begin
                        t1:=maxlongint;
                        t2:=maxlongint;
                        if ((a*i+b-d) mod c=0) and (a*i+b-d>=0) then t1:=a*i+b;
                        if ((c*i+d-b) mod a=0) and (c*i+d-b>=0) then t2:=c*i+d;
                        if min(t1,t2)<maxlongint then
                                begin
                                        rslt:=min(t1,t2);
                                        break;
                                end;
                end;
        write(rslt);
        //close(input);
        //close(output);
end.
