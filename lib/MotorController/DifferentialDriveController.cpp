#include "DifferentialDriveController.hpp"
#include "../MathHelper/MathHelper.h"
#include "../Logger/Logger.hpp"

DifferentialDriveController::DifferentialDriveController(float wheelsRadius,
  float wheelsDistanceFromRotationAxis)
{
  setWheelsRadius(wheelsRadius);
  setWheelsDistanceFromRotationAxis(wheelsDistanceFromRotationAxis);
}

void DifferentialDriveController::setWheelsRadius(float wheelsRadius)
{
#ifdef DEBUG
  if(wheelsRadius <= 0)
  {
    CurrentLogger->writeLine("[DifferentialDriveController::setWheelsRadius] O raio das rodas não pode ser menor ou igual a 0");
    return;
  }
#endif
  m_WheelsRadius = wheelsRadius;
}


void DifferentialDriveController::setWheelsDistanceFromRotationAxis(float wheelsDistanceFromRotationAxis)
{
#ifdef DEBUG
  if(wheelsDistanceFromRotationAxis <= 0)
  {
    CurrentLogger->writeLine("[DifferentialDriveController::setWheelsDistanceFromRotationAxis] A distância entre as rodas deve ser maior ou igual a 0");
    return;
  }
#endif
  m_WheelsDistanceFromRotationAxis = wheelsDistanceFromRotationAxis;
}

void DifferentialDriveController::move(float linearVelocity, float angularVelocity)
{
  m_LeftVelocity = ((2 * linearVelocity) + (angularVelocity * m_WheelsDistanceFromRotationAxis)) / (2 * m_WheelsRadius);
  m_RightVelocity = ((2 * linearVelocity) - (angularVelocity * m_WheelsDistanceFromRotationAxis)) / (2 * m_WheelsRadius);
  // Saturação de velocidade é feita nas implementações derivadas que precisarem disso
}
