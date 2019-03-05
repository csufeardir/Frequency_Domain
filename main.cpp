cv::Mat tempMat = cv::Mat::zeroMat(1,1,CV_64FC1);


for (int m=0; m<M, m++){
	for (int n=0; n<N/2; n++){
		double m_new, n_new;
		if(m<M/2){
		m_new=m+(M/2);
		n_new=n+(N/2);
		}
		else{
		m_new=(M/2)-m;
		n_new=(N/2)-n;
		}
		
		tempMat.at<double>(0,0)=dft_64fc1_img_imaginary_part.at<double>(m,n)
		dft_64fc1_img_imaginary_part.at<double>(m,n)=dft_64fc1_img_imaginary_part.at<double>(m_new,n_new);
		dft_64fc1_img_imaginary_part.at<double>(m_new,n_new)=tempMat.at<double>(0,0);
		
		
	}
}

cv::Mat highpassMask = cv::Mat::zeroMat(64,64,CV_64FC1);
cv::Point center;
center.x=32;
center.y=32;
cv::Scalar White(255);
cv::Circle(highpassMask, center, 16, White, -1);
cv::imshow("High Pass Mask", highpassMask);



for (int m=0, m<M, m++){
	for (int n=0; n<N; n++){
		if(highpassMask.at<double>(m,n) != 255){
			dft_64fc1_img_imaginary_part.at<double>(m,n)=0;
		}
	}
}


for (int m=0; m<M, m++){
	for (int n=0; n<N/2; n++){
		double m_new, n_new;
		if(m<M/2){
		m_new=m+(M/2);
		n_new=n+(N/2);
		}
		else{
		m_new=(M/2)-m;
		n_new=(N/2)-n;
		}
			tempMat.at<double>(0,0)=dft_64fc1_img_imaginary_part.at<double>(m,n)
			dft_64fc1_img_imaginary_part.at<double>(m,n)=dft_64fc1_img_imaginary_part.at<double>(m_new,n_new);
			dft_64fc1_img_imaginary_part.at<double>(m_new,n_new)=tempMat.at<double>(0,0);
	}
}

cv::Mat inverse_dft_64fc1_img_real_part = cv::Mat::zeroMat(64,64,CV_64FC1);
cv::Mat inverse_dft_64fc1_img_imaginary_part = cv::Mat::zeroMat(64,64,CV_64FC1);
cv::Mat output_inverse_dft_total = cv::Mat::zeroMat(64,64,CV_64FC1);
		
		
