const fi='a.inp';
      fo='a.out';
var w:array[0..100005] of longint;
    n,k,i,t:longint;
    rslt:int64;
begin
        //assign(input,fi); reset(input);
        //assign(output,fo); rewrite(output);
        readln(n,k);
        for i:=1 to n do read(w[i]);
        rslt:=0;
        for i:=1 to n do
                begin
                        rslt:=rslt+int64(w[i] div (k*2));
                        w[i]:=w[i] mod (k*2);
                end;
        t:=0;
        for i:=1 to n do
                begin
                        t:=t+w[i] div k;
                        if w[i] mod k>0 then inc(t);
                end;
        if t mod 2<>0 then inc(t);
        t:=t div 2;
        rslt:=rslt+t;
        write(rslt);
        //close(input);
        //close(output);
end.
