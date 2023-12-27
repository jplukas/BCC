function calculateError(originalImg, decompressedImg)
    originalImg = double(imread(originalImg));
    decompressedImg = double(imread(decompressedImg));
    err1 = norm(originalImg(:,:,1) - decompressedImg(:,:,1)) / norm(originalImg(:,:,1));
    err2 = norm(originalImg(:,:,2) - decompressedImg(:,:,2)) / norm(originalImg(:,:,2));
    err3 = norm(originalImg(:,:,3) - decompressedImg(:,:,3)) / norm(originalImg(:,:,3));
    err = double(err1 + err2 + err3) / 3.0;
    disp(err);
endfunction