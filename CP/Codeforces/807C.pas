uses math;
const fi='';
      fo='';
var t,p,q,x,y,tmp:int64;
begin
        assign(input,fi); reset(input);
        assign(output,fo); rewrite(output);
        readln(t);
        repeat
                readln(x,y,p,q);
                if (p=0) and (x=0) then writeln(0)
                else if p=0 then writeln(-1)
                else if (x=y) and (p=q) then writeln(0)
                else if p=q then writeln(-1)
                else
                        begin
                                tmp:=max(x div p,max(y div q,(y-x) div (q-p)));
                                if (p*tmp<x) or (q*tmp<y) or (q*tmp-y<p*tmp-x) then inc(tmp);
                                writeln(q*tmp-y);
                        end;
                dec(t);
        until t=0;
        close(input);
        close(output);
end.
