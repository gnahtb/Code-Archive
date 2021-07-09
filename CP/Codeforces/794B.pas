const fi='';
      fo='';
      lim=1000;
var x:array[0..lim+5] of real;
    n:longint;
    h:real;
procedure enter;
begin
        assign(input,fi);
        reset(input);
        readln(n,h);
        close(input);
end;
procedure solve;
var i,m:longint;
    t:real;
begin
        fillchar(x,sizeof(x),0);
        for i:=1 to n-1 do
                begin
                        t:=h*sqrt(i/n);
                        x[i]:=t;
                end;
end;
procedure print;
var i:longint;
begin
        assign(output,fo);
        rewrite(output);
        for i:=1 to n-1 do write(x[i]:0:12,#32);
        close(output);
end;
begin
        enter;
        solve;
        print;
end.
