struct alignas(64) candle{
  double open;
  double high;
  double low;
  double close;
};

extern candle* period[];
void MketData();
