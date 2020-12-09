const fi='';
      fo='';
      lim=200000;
var a:array[0..lim+5] of longint;
    n,k:longint;
    r:real;
procedure enter;
var i:longint;
begin
        assign(input,fi);
        reset(input);
        readln(n,k);
        for i:=1 to n do read(a[i]);
        close(input);
end;
procedure solve;
var i:longint;
    t:int64;
begin
        t:=0;
        for i:=1 to k-1 do t:=t+a[i];
        r:=0;
        for i:=k to n do
                begin
                        t:=t+a[i];
                        r:=r+(t/(n-k+1));
                        t:=t-a[i-k+1];
                end;
end;
procedure print;
begin
        assign(output,fo);
        rewrite(output);
        write(r:0:6);
        close(output);
end;
begin
        enter;
        solve;
        print;
end.
