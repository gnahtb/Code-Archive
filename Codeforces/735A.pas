const fi='';
      fo='';
var str,r:string;
    s,n,k:longint;
procedure enter;
begin
        assign(input,fi);
        reset(input);
        readln(n,k);
        readln(str);
        close(input);
end;
procedure init;
begin
        for s:=1 to n do
                if str[s]='G' then
                        break;
end;
procedure solve;
var i:longint;
begin
        i:=s;
        while (i-k>0) and (str[i-k] in ['T','.']) do
                begin
                        dec(i,k);
                        if str[i]='T' then
                                begin
                                        r:='YES';
                                        exit;
                                end;
                end;
        i:=s;
        while (i+k<=n) and (str[i+k] in ['T','.']) do
                begin
                        inc(i,k);
                        if str[i]='T' then
                                begin
                                        r:='YES';
                                        exit;
                                end;
                end;
end;
procedure print;
begin
        assign(output,fo);
        rewrite(output);
        write(r);
        close(output);
end;
begin
        enter;
        init;
        r:='NO';
        solve;
        print;
end.
