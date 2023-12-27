function makeimg(s)
    A = uint8(zeros(s, s, 3));

    rang = double(1:s)/ (s / 10.0);
    rang_0 = rang - rang(floor(s/2));

    XpY = repmat(rang, s, 1) + repmat(rang, s, 1)';
    XtY = repmat(rang, s, 1) .* repmat(rang, s, 1)';
    XpY_0 = repmat(rang_0, s, 1) + repmat(rang_0, s, 1)';
    XtY_0 = repmat(rang_0, s, 1) .* repmat(rang_0, s, 1)';
    X2pY2_0 = sqrt((repmat(rang_0, s, 1) .**2) + (repmat(rang_0, s, 1)'.**2));
    X2pY2 = sqrt((repmat(rang, s, 1) .**2) + (repmat(rang, s, 1)'.**2));

    A(:, :, 1) = A(:, :, 3) = repmat(normalize(sin(rang)), s, 1);
    A(:, :, 2) = normalize(sin(XpY));
    fname = strcat("in_",num2str(1), ".png");
    imwrite(A,fname,'Quality',100);

    A(:, :, 1) = repmat(normalize(cos(rang)), s, 1);
    A(:, :, 2) = normalize(sin(XtY));
    A(:, :, 3) = repmat(normalize(sin(rang)), s, 1)';
    fname = strcat("in_",num2str(2), ".png");
    imwrite(A,fname,'Quality',100);

    A(:, :, 1) = repmat(normalize(sin(rang_0)), s, 1);
    A(:, :, 2) = normalize(X2pY2_0);
    A(:, :, 3) = normalize(X2pY2);
    fname = strcat("in_",num2str(3), ".png");
    imwrite(A,fname,'Quality',100);

    A(:, :, 1) = repmat(normalize(sin(rang_0)), s, 1);
    A(:, :, 2) = A(:, :, 1);
    A(:, :, 3) = A(:, :, 1);
    fname = strcat("in_",num2str(4), ".png");
    imwrite(A,fname,'Quality',100);

    A(:, :, 1) = normalize(sin(XpY));
    A(:, :, 2) = A(:, :, 1);
    A(:, :, 3) = A(:, :, 1);
    fname = strcat("in_",num2str(5), ".png");
    imwrite(A,fname,'Quality',100);

    A(:, :, 1) = normalize(X2pY2);
    A(:, :, 2) = A(:, :, 1);
    A(:, :, 3) = A(:, :, 1);
    fname = strcat("in_",num2str(6), ".png");
    imwrite(A,fname,'Quality',100);
endfunction

function M = normalize(A)
    max_v = max(max(A));
    min_v = min(min(A));
    r = max_v - min_v;
    M = uint8(floor(255.0 * ((A - min_v)/r)));
endfunction