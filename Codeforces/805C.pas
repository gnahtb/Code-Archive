uses math;
const fi='';
      fo='';
var n,rslt,t:longint;
begin
        assign(input,fi); reset(input);
        assign(output,fo); rewrite(output);
        readln(n);
        rslt:=(n div 2-1) mod (n+1);
        if odd(n) then
                begin
                        t:=((n div 2)*2+1) mod (n+1);
                        rslt:=rslt+min(t,1);
                end;
        write(rslt);
        close(input);
        close(output);
end.
