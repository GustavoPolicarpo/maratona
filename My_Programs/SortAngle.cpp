ponto p0;

double Angle(ponto p){
	double dx = p0.x - p.x;
    double dy = p0.y - p.y;
    double r = sqrt(dx * dx + dy * dy);
    double angle = atan2(dy , dx);
    if(angle < 0) angle += M_PI * 2;
    return angle;
}
bool mysort(ponto a, ponto b){
	if(Angle(a) < Angle(b)) return true;
	return false;
}
