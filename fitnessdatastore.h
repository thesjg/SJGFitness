#ifndef FITNESSDATASTORE_H
#define FITNESSDATASTORE_H

#include <QObject>

class FitnessDataStore : public QObject
{
	Q_OBJECT

public:
	FitnessDataStore(QObject *parent);
	~FitnessDataStore();

private:
	
};

#endif // FITNESSDATASTORE_H
