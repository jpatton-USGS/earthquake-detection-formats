#include <detection-formats.h>
#include <gtest/gtest.h>

#include <string>

// test data
#include "unittest_data.h" // NOLINT

void checkdata(detectionformats::correlation correlationobject,
		std::string testinfo) {
	// check id
	if (correlationobject.id.empty() != true) {
		std::string correlationid = correlationobject.id;
		std::string expectedid = std::string(ID);
		ASSERT_STREQ(correlationid.c_str(), expectedid.c_str());
	}

	// check station
	if (correlationobject.site.station.empty() != true) {
		std::string sitestation = correlationobject.site.station;
		std::string expectedstation = std::string(STATION);
		ASSERT_STREQ(sitestation.c_str(), expectedstation.c_str());
	}

	// check channel
	if (correlationobject.site.channel.empty() != true) {
		std::string sitechannel = correlationobject.site.channel;
		std::string expectedchannel = std::string(CHANNEL);
		ASSERT_STREQ(sitechannel.c_str(), expectedchannel.c_str());
	}

	// check network
	if (correlationobject.site.network.empty() != true) {
		std::string sitenetwork = correlationobject.site.network;
		std::string expectednetwork = std::string(NETWORK);
		ASSERT_STREQ(sitenetwork.c_str(), expectednetwork.c_str());
	}

	// check location
	if (correlationobject.site.location.empty() != true) {
		std::string sitelocation = correlationobject.site.location;
		std::string expectedlocation = std::string(LOCATION);
		ASSERT_STREQ(sitelocation.c_str(), expectedlocation.c_str());
	}

	// check agencyid
	if (correlationobject.source.agencyid.empty() != true) {
		std::string sourceagencyid = correlationobject.source.agencyid;
		std::string expectedagencyid = std::string(AGENCYID);
		ASSERT_STREQ(sourceagencyid.c_str(), expectedagencyid.c_str());
	}

	// check author
	if (correlationobject.source.author.empty() != true) {
		std::string sourceauthor = correlationobject.source.author;
		std::string expectedauthor = std::string(AUTHOR);
		ASSERT_STREQ(sourceauthor.c_str(), expectedauthor.c_str());
	}

	// check phase
	if (correlationobject.phase.empty() != true) {
		std::string correlationphase = correlationobject.phase;
		std::string expectedphase = std::string(PHASE);
		ASSERT_STREQ(correlationphase.c_str(), expectedphase.c_str());
	}

	// check time
	if (std::isnan(correlationobject.time) != true) {
		double correlationtime = correlationobject.time;
		double expectedtime = detectionformats::ConvertISO8601ToEpochTime(
				std::string(TIME));
		ASSERT_EQ(correlationtime, expectedtime);
	}

	// check correlation
	if (std::isnan(correlationobject.correlationvalue) != true) {
		double correlationcorrelation = correlationobject.correlationvalue;
		double expectedcorrelation = CORRELATION;
		ASSERT_EQ(correlationcorrelation, expectedcorrelation);
	}

	// check latitude
	if (std::isnan(correlationobject.hypocenter.latitude) != true) {
		double correlationlatitude = correlationobject.hypocenter.latitude;
		double expectedlatitude = LATITUDE;
		ASSERT_EQ(correlationlatitude, expectedlatitude);
	}

	// check longitude
	if (std::isnan(correlationobject.hypocenter.longitude) != true) {
		double correlationlongitude = correlationobject.hypocenter.longitude;
		double expectedlongitude = LONGITUDE;
		ASSERT_EQ(correlationlongitude, expectedlongitude);
	}

	// check origintime
	if (std::isnan(correlationobject.hypocenter.time) != true) {
		double correlationorigintime = correlationobject.hypocenter.time;
		double expectedorigintime = detectionformats::ConvertISO8601ToEpochTime(
				std::string(TIME));
		ASSERT_EQ(correlationorigintime, expectedorigintime);
	}

	// check depth
	if (std::isnan(correlationobject.hypocenter.depth) != true) {
		double correlationdepth = correlationobject.hypocenter.depth;
		double expecteddepth = DEPTH;
		ASSERT_EQ(correlationdepth, expecteddepth);
	}

	// check latitude error
	if (std::isnan(correlationobject.hypocenter.latitudeerror) != true) {
		double correlationlatitudeerror =
			correlationobject.hypocenter.latitudeerror;
		double expectedlatitudeerror = LATITUDEERROR;
		ASSERT_EQ(correlationlatitudeerror, expectedlatitudeerror);
	}

	// check longitude error
	if (std::isnan(correlationobject.hypocenter.longitudeerror) != true) {
		double correlationlongitdeerror =
				correlationobject.hypocenter.longitudeerror;
		double expectedlongitudeerror = LONGITUDEERROR;
		ASSERT_EQ(correlationlongitdeerror, expectedlongitudeerror);
	}

	// check time error
	if (std::isnan(correlationobject.hypocenter.timeerror) != true) {
		double correlationtimeerror = correlationobject.hypocenter.timeerror;
		double expectedtimeerror = TIMEERROR;
		ASSERT_EQ(correlationtimeerror, expectedtimeerror);
	}

	// check depth error
	if (std::isnan(correlationobject.hypocenter.deptherror) != true) {
		double correlationdeptherror = correlationobject.hypocenter.deptherror;
		double expecteddeptherror = DEPTHERROR;
		ASSERT_EQ(correlationdeptherror, expecteddeptherror);
	}

	// check eventtype
	if (correlationobject.eventtype.type.empty() != true) {
		std::string detectioneventtype = correlationobject.eventtype.type;
		std::string expectedeventtype = std::string(EVENTTYPE);
		ASSERT_STREQ(detectioneventtype.c_str(), expectedeventtype.c_str());
	}

	// check eventtype certainty
	if (correlationobject.eventtype.certainty.empty() != true) {
		std::string detectioneventtypecertainty =
			correlationobject.eventtype.certainty;
		std::string expectedeventtypecertainty = std::string(CERTAINTY);
		ASSERT_STREQ(detectioneventtypecertainty.c_str(),
			expectedeventtypecertainty.c_str());
	}

	// check magnitude
	if (std::isnan(correlationobject.magnitude) != true) {
		double correlationmagnitude = correlationobject.magnitude;
		double expectedmagnitude = MAGNITUDE;
		ASSERT_EQ(correlationmagnitude, expectedmagnitude);
	}

	// check snr
	if (std::isnan(correlationobject.snr) != true) {
		double correlationsnr = correlationobject.snr;
		double expectedsnr = SNR;
		ASSERT_EQ(correlationsnr, expectedsnr);
	}

	// check zscore
	if (std::isnan(correlationobject.zscore) != true) {
		double correlationzscore = correlationobject.zscore;
		double expectedzscore = ZSCORE;
		ASSERT_EQ(correlationzscore, expectedzscore);
	}

	// check detectionthreshold
	if (std::isnan(correlationobject.detectionthreshold) != true) {
		double correlationdetectionthreshold =
			correlationobject.detectionthreshold;
		double expecteddetectionthreshold = DETECTIONTHRESHOLD;
		ASSERT_EQ(correlationdetectionthreshold, expecteddetectionthreshold);
	}

	// check thresholdtype
	if (correlationobject.thresholdtype.empty() != true) {
		std::string correlationthresholdtype = correlationobject.thresholdtype;
		std::string expectedthresholdtype = std::string(THRESHOLDTYPE);
		ASSERT_STREQ(correlationthresholdtype.c_str(),
				expectedthresholdtype.c_str());
	}

	// associationinfo
	if (correlationobject.associationinfo.isempty() == false) {
		// check phase
		if (correlationobject.associationinfo.phase.empty() != true) {
			std::string associationphase =
				correlationobject.associationinfo.phase;
			std::string expectedassociationphase = std::string(PHASE);
			ASSERT_STREQ(associationphase.c_str(),
				expectedassociationphase.c_str());
		}

		// check distance
		if (std::isnan(correlationobject.associationinfo.distance) != true) {
			double associationdistance =
				correlationobject.associationinfo.distance;
			double expecteddistance = DISTANCE;
			ASSERT_EQ(associationdistance, expecteddistance);
		}

		// check azimuth
		if (std::isnan(correlationobject.associationinfo.azimuth) != true) {
			double associationazimuth =
				correlationobject.associationinfo.azimuth;
			double expectedazimuth = AZIMUTH;
			ASSERT_EQ(associationazimuth, expectedazimuth);
		}

		// check residual
		if (std::isnan(correlationobject.associationinfo.residual) != true) {
			double associationresidual =
				correlationobject.associationinfo.residual;
			double expectedresidual = RESIDUAL;
			ASSERT_EQ(associationresidual, expectedresidual);
		}

		// check sigma
		if (std::isnan(correlationobject.associationinfo.sigma) != true) {
			double associationsigma = correlationobject.associationinfo.sigma;
			double expectedsigma = SIGMA;
			ASSERT_EQ(associationsigma, expectedsigma);
		}
	}
}

// tests to see if correlation can successfully
// write json output
TEST(CorrelationTest, WritesJSON) {
	detectionformats::correlation correlationobject;

	// build correlation object
	correlationobject.id = std::string(ID);

	// site subobject
	correlationobject.site.station = std::string(STATION);
	correlationobject.site.channel = std::string(CHANNEL);
	correlationobject.site.network = std::string(NETWORK);
	correlationobject.site.location = std::string(LOCATION);

	// source subobject
	correlationobject.source.agencyid = std::string(AGENCYID);
	correlationobject.source.author = std::string(AUTHOR);

	correlationobject.time = detectionformats::ConvertISO8601ToEpochTime(
			std::string(TIME));
	correlationobject.phase = std::string(PHASE);
	correlationobject.correlationvalue = CORRELATION;
	correlationobject.hypocenter.latitude = LATITUDE;
	correlationobject.hypocenter.longitude = LONGITUDE;
	correlationobject.hypocenter.time =
			detectionformats::ConvertISO8601ToEpochTime(
					std::string(TIME));
	correlationobject.hypocenter.depth = DEPTH;
	correlationobject.hypocenter.latitudeerror = LATITUDEERROR;
	correlationobject.hypocenter.longitudeerror = LONGITUDEERROR;
	correlationobject.hypocenter.timeerror = TIMEERROR;
	correlationobject.hypocenter.deptherror = DEPTHERROR;
	correlationobject.eventtype.type = std::string(EVENTTYPE);
	correlationobject.eventtype.certainty = std::string(CERTAINTY);
	correlationobject.magnitude = MAGNITUDE;
	correlationobject.snr = SNR;
	correlationobject.zscore = ZSCORE;
	correlationobject.detectionthreshold = DETECTIONTHRESHOLD;
	correlationobject.thresholdtype = std::string(THRESHOLDTYPE);

	// association subobject
	correlationobject.associationinfo.phase = std::string(PHASE);
	correlationobject.associationinfo.distance = DISTANCE;
	correlationobject.associationinfo.azimuth = AZIMUTH;
	correlationobject.associationinfo.residual = RESIDUAL;
	correlationobject.associationinfo.sigma = SIGMA;

	// build json string
	rapidjson::Document correlationdocument;
	std::string correlationjson = detectionformats::ToJSONString(
			correlationobject.tojson(correlationdocument,
					correlationdocument.GetAllocator()));

	// read it back in
	rapidjson::Document correlationdocument2;
	detectionformats::correlation correlationobject2(
			detectionformats::FromJSONString(correlationjson,
					correlationdocument2));

	// check data values
	checkdata(correlationobject2, "");
}

// tests to see if correlation can successfully
// read json output
TEST(CorrelationTest, ReadsJSON) {
	// build association object
	rapidjson::Document correlationdocument;
	detectionformats::correlation correlationobject(
			detectionformats::FromJSONString(std::string(CORRELATIONSTRING),
					correlationdocument));

	// check data values
	checkdata(correlationobject, "");
}

// tests to see if correlation can successfully
// be constructed
TEST(CorrelationTest, Constructor) {
	// use constructor
	detectionformats::correlation correlationobject(std::string(ID),
			std::string(STATION), std::string(CHANNEL),
			std::string(NETWORK), std::string(LOCATION), std::string(AGENCYID),
			std::string(AUTHOR), std::string(PHASE),
			detectionformats::ConvertISO8601ToEpochTime(std::string(TIME)),
			CORRELATION, LATITUDE, LONGITUDE,
			detectionformats::ConvertISO8601ToEpochTime(
					std::string(TIME)), DEPTH, LATITUDEERROR,
			LONGITUDEERROR, TIMEERROR, DEPTHERROR, std::string(EVENTTYPE),
			std::string(CERTAINTY), MAGNITUDE, SNR, ZSCORE, DETECTIONTHRESHOLD,
			std::string(THRESHOLDTYPE));

	// check data values
	checkdata(correlationobject, "Tested Constructor");

	// use constructor
	detectionformats::correlation correlationobject_altc1(std::string(ID),
			std::string(STATION), std::string(CHANNEL),
			std::string(NETWORK), std::string(LOCATION), std::string(AGENCYID),
			std::string(AUTHOR), std::string(PHASE),
			detectionformats::ConvertISO8601ToEpochTime(std::string(TIME)),
			CORRELATION, LATITUDE, LONGITUDE,
			detectionformats::ConvertISO8601ToEpochTime(
					std::string(TIME)), DEPTH, LATITUDEERROR,
			LONGITUDEERROR, TIMEERROR, DEPTHERROR, std::string(EVENTTYPE),
			std::string(CERTAINTY), MAGNITUDE, SNR, ZSCORE, DETECTIONTHRESHOLD,
			std::string(THRESHOLDTYPE), std::string(PHASE), DISTANCE,
			AZIMUTH, RESIDUAL, SIGMA);

	// check data values
	checkdata(correlationobject_altc1, "Tested Alternate Constructor 1");

	detectionformats::correlation correlationobject_altc2(std::string(ID),
			detectionformats::site(std::string(STATION),
					std::string(CHANNEL), std::string(NETWORK),
					std::string(LOCATION)),
			detectionformats::source(std::string(AGENCYID),
					std::string(AUTHOR)), std::string(PHASE),
			detectionformats::ConvertISO8601ToEpochTime(std::string(TIME)),
					CORRELATION,
			detectionformats::hypocenter(LATITUDE, LONGITUDE,
					detectionformats::ConvertISO8601ToEpochTime(
					std::string(TIME)), DEPTH, LATITUDEERROR,
					LONGITUDEERROR, TIMEERROR, DEPTHERROR),
			detectionformats::eventtype(std::string(EVENTTYPE),
					std::string(CERTAINTY)),
			MAGNITUDE, SNR, ZSCORE, DETECTIONTHRESHOLD,
			std::string(THRESHOLDTYPE));

	// check data values
	checkdata(correlationobject_altc2, "Tested Alternate Constructor 2");

	detectionformats::correlation correlationobject_altc3(std::string(ID),
			detectionformats::site(std::string(STATION),
					std::string(CHANNEL), std::string(NETWORK),
					std::string(LOCATION)),
			detectionformats::source(std::string(AGENCYID),
					std::string(AUTHOR)), std::string(PHASE),
			detectionformats::ConvertISO8601ToEpochTime(std::string(TIME)),
					CORRELATION,
			detectionformats::hypocenter(LATITUDE, LONGITUDE,
					detectionformats::ConvertISO8601ToEpochTime(
					std::string(TIME)), DEPTH, LATITUDEERROR,
					LONGITUDEERROR, TIMEERROR, DEPTHERROR),
			detectionformats::eventtype(std::string(EVENTTYPE),
					std::string(CERTAINTY)),
			MAGNITUDE, SNR, ZSCORE, DETECTIONTHRESHOLD,
			std::string(THRESHOLDTYPE),
			detectionformats::association(std::string(PHASE), DISTANCE,
			AZIMUTH, RESIDUAL, SIGMA));

	// check data values
	checkdata(correlationobject_altc3, "Tested Alternate Constructor 3");

	// json constructor (empty)
    rapidjson::Value emptyvalue(rapidjson::kObjectType);
    detectionformats::correlation correlationobject2(emptyvalue);

    // check data values
	checkdata(correlationobject2, "");
}

// tests to see if correlation can successfully
// be copy constructed
TEST(CorrelationTest, CopyConstructor) {
	// use constructor
	detectionformats::correlation fromcorrelationobject(std::string(ID),
			std::string(STATION), std::string(CHANNEL),
			std::string(NETWORK), std::string(LOCATION), std::string(AGENCYID),
			std::string(AUTHOR), std::string(PHASE),
			detectionformats::ConvertISO8601ToEpochTime(std::string(TIME)),
			CORRELATION, LATITUDE, LONGITUDE,
			detectionformats::ConvertISO8601ToEpochTime(
					std::string(TIME)), DEPTH, LATITUDEERROR,
			LONGITUDEERROR, TIMEERROR, DEPTHERROR, std::string(EVENTTYPE),
			std::string(CERTAINTY), MAGNITUDE, SNR, ZSCORE, DETECTIONTHRESHOLD,
			std::string(THRESHOLDTYPE), std::string(PHASE), DISTANCE,
			AZIMUTH, RESIDUAL, SIGMA);

	detectionformats::correlation correlationobject(fromcorrelationobject);

	// check data values
	checkdata(correlationobject, "");
}

// tests to see if correlation can successfully
// validate
TEST(CorrelationTest, Validate) {
	detectionformats::correlation correlationobject;

	// build correlation object
	correlationobject.id = std::string(ID);

	// site subobject
	correlationobject.site.station = std::string(STATION);
	correlationobject.site.channel = std::string(CHANNEL);
	correlationobject.site.network = std::string(NETWORK);
	correlationobject.site.location = std::string(LOCATION);

	// source subobject
	correlationobject.source.agencyid = std::string(AGENCYID);
	correlationobject.source.author = std::string(AUTHOR);

	correlationobject.time = detectionformats::ConvertISO8601ToEpochTime(
			std::string(TIME));
	correlationobject.phase = std::string(PHASE);
	correlationobject.correlationvalue = CORRELATION;
	correlationobject.hypocenter.latitude = LATITUDE;
	correlationobject.hypocenter.longitude = LONGITUDE;
	correlationobject.hypocenter.time =
			detectionformats::ConvertISO8601ToEpochTime(
					std::string(TIME));
	correlationobject.hypocenter.depth = DEPTH;
	correlationobject.hypocenter.latitudeerror = LATITUDEERROR;
	correlationobject.hypocenter.longitudeerror = LONGITUDEERROR;
	correlationobject.hypocenter.timeerror = TIMEERROR;
	correlationobject.hypocenter.deptherror = DEPTHERROR;
	correlationobject.eventtype.type = std::string(EVENTTYPE);
	correlationobject.eventtype.certainty = std::string(CERTAINTY);
	correlationobject.magnitude = MAGNITUDE;
	correlationobject.snr = SNR;
	correlationobject.zscore = ZSCORE;
	correlationobject.detectionthreshold = DETECTIONTHRESHOLD;
	correlationobject.thresholdtype = std::string(THRESHOLDTYPE);

	// association subobject
	correlationobject.associationinfo.phase = std::string(PHASE);
	correlationobject.associationinfo.distance = DISTANCE;
	correlationobject.associationinfo.azimuth = AZIMUTH;
	correlationobject.associationinfo.residual = RESIDUAL;
	correlationobject.associationinfo.sigma = SIGMA;

	// successful validation
	bool result = correlationobject.isvalid();

	// check return code
	ASSERT_EQ(result, true)<< "Tested for successful validation.";

	// build bad correlation object
	detectionformats::correlation badcorrelationobject;

	result = false;
	try {
		// call validation
		result = badcorrelationobject.isvalid();
	} catch (const std::exception &) {
		// don't care what the exception was
	}

	// check return code
	ASSERT_EQ(result, false)<< "Tested for unsuccessful validation.";

	// build bad correlation object
	detectionformats::correlation badcorrelationobject2;
	badcorrelationobject2.phase = "22";
	badcorrelationobject2.time = -1000000000000;
	badcorrelationobject2.correlationvalue = -9999;
	badcorrelationobject2.eventtype.type = "fjyord";
	badcorrelationobject2.eventtype.certainty = "nah";
	badcorrelationobject2.magnitude = -9;
	badcorrelationobject2.snr = -9;

	result = false;
	try {
		// call validation
		result = badcorrelationobject2.isvalid();
	} catch (const std::exception &) {
		// don't care what the exception was
	}

	// check return code
	ASSERT_EQ(result, false)<< "Tested for unsuccessful validation.";
}
