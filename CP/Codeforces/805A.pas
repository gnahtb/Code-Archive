const fi='';
      fo='';
var l,r,t,rslt,max,i:longint;
begin
        assign(input,fi); reset(input);
        assign(output,fo); rewrite(output);
        readln(l,r);
        rslt:=2;
        if (r-l=0) and odd(l) then rslt:=l;
        write(rslt);
        close(input);
        close(output);
end.

