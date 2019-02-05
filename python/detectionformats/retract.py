#!/usr/bin/env python

#package imports
import detectionformats.source

#stdlib imports
import json

class Retract:
    """ Retract - a conversion class used to create, parse, and validate a 
        retraction as part of detection data.
    """
    # json keys
    TYPE_KEY = "Type"
    ID_KEY = "ID"
    SOURCE_KEY = "Source"

    def __init__(self, newID=None, newSource=None):
        """Initialize the retract object. Constructs an empty object
           if all arguments are None

        Args:
            newID: a required String containing the desired ID
            newSource: a required detectionformats.source.Source containing the
                desired source
        Returns:
            Nothing
        Raises:
            Nothing
        """
        # first required keys
        self.type = 'Retract'

        if newID is not None:
            self.id = newID

        if newSource is not None:
            self.source = newSource
        else:
            self.source = detectionformats.source.Source()

    def fromJSONString(self, jsonString):
        """Populates the object from a json formatted string

        Args:
            jsonString: a required String containing the json formatted text
        Returns:
            Nothing
        Raises:
            Nothing
        """
        jsonObject = json.loads(jsonString)
        self.fromDict(jsonObject)

    def fromDict(self, aDict):
        """Populates the object from a dictionary

        Args:
            aDict: a required dictionary
        Returns:
            Nothing
        Raises:
            Nothing
        """
        # first required keys
        try:
            self.type = aDict[self.TYPE_KEY]
            self.id = aDict[self.ID_KEY]
            self.source.fromDict(aDict[self.SOURCE_KEY])
        except(ValueError, KeyError, TypeError) as e:
            print("Dict format error, missing required keys: %s" % e)

    def toJSONString(self):
        """Converts the object to a json formatted string

        Args:
            None
        Returns:
            The JSON formatted message as a String
        Raises:
            Nothing
        """
        jsonObject = self.toDict()

        return json.dumps(jsonObject, ensure_ascii=False)

    def toDict(self):
        """Converts the object to a dictionary

        Args:
            None
        Returns:
            The dictionary
        Raises:
            Nothing
        """
        aDict = {}

        # first required keys
        try:
            aDict[self.TYPE_KEY] = self.type
            aDict[self.ID_KEY] = self.id
            aDict[self.SOURCE_KEY] = self.source.toDict()
        except(NameError, AttributeError) as e:
            print("Missing required data error: %s" % e)

        return aDict

    def isValid(self):
        """Checks to see if the object is valid

        Args:
            None
        Returns:
            True if the object is valid, False otherwise
        Raises:
            Nothing
        """
        errorList = self.getErrors()

        return not errorList

    def getErrors(self):
        """Gets a list of object validation errors

        Args:
            None
        Returns:
            A List of Strings containing the validation error messages
        Raises:
            Nothing
        """
        errorList = []

        try:
            if self.type == '':
                errorList.append('Empty Type in Retract Class.')
            elif self.type != 'Retract':
                errorList.append('Non-Retract Type in Retract Class.')
        except(NameError, AttributeError):
            errorList.append('No Type in Retract Class.')

        try:
            if self.id == '':
                errorList.append('Empty ID in Retract Class.')
        except(NameError, AttributeError):
            errorList.append('No ID in Retract Class.')

        try:
            if not self.source.isValid():
                errorList.append('Invalid Source in Retract Class.')
        except(NameError, AttributeError):
            errorList.append('No Source in Retract Class.')

        return errorList
