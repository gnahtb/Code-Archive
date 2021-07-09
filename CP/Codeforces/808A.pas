uses math;
const fi='';
      fo='';
var s:string;
    n,r:longint;
begin
        assign(input,fi); reset(input);
        assign(output,fo); rewrite(output);
        readln(n);
        if n<9 then
                r:=n+1
        else
                begin
                        str(n,s);
                        r:=ord(s[1])-47;
                        r:=r*10**(length(s)-1);
                end;
        writeln(r-n);
        close(input);
        close(output);
end.
