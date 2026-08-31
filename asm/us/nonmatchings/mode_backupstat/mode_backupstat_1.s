.syntax unified
	.align 2, 0
	.global mode_backupstat_1
	.thumb
	.thumb_func
	.type mode_backupstat_1, %function
mode_backupstat_1: @ 08109958
	push {r4, r5, lr}
	ldr r4, _08109970 @ =0x02035FE8
	ldrb r5, [r4, #0x00]
	bl GetKeysRepeat
	movs r1, #0x40
	ands r1, r0
	cmp r1, #0x00
	beq _08109974
	ldrb r0, [r4, #0x00]
	subs r0, #0x01
	b _08109984
_08109970: .4byte 0x02035FE8
_08109974:
	bl GetKeysRepeat
	movs r1, #0x80
	ands r1, r0
	cmp r1, #0x00
	beq _08109986
	ldrb r0, [r4, #0x00]
	adds r0, #0x01
_08109984:
	strb r0, [r4, #0x00]
_08109986:
	ldr r2, _081099A4 @ =0x02035FE8
	movs r1, #0x00
	ldsb r1, [r2, r1]
	cmp r5, r1
	beq _081099EA
	adds r0, r1, #0x0
	cmp r0, #0x00
	bge _081099AC
	ldr r0, _081099A8 @ =0x02035FE9
	ldrb r0, [r0, #0x00]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #0x01
	subs r0, #0x01
	b _081099BC
_081099A4: .4byte 0x02035FE8
_081099A8: .4byte 0x02035FE9
_081099AC:
	ldr r0, _08109A24 @ =0x02035FE9
	ldrb r0, [r0, #0x00]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #0x01
	cmp r1, r0
	blt _081099BE
	movs r0, #0x00
_081099BC:
	strb r0, [r2, #0x00]
_081099BE:
	lsls r1, r5, #0x03
	adds r1, r1, r5
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldr r3, _08109A28 @ =0x09993888
	movs r0, #0x00
	movs r2, #0x02
	bl func_0805FCB0
	ldr r0, _08109A2C @ =0x02035FE8
	ldrb r0, [r0, #0x00]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r1, r0, #0x03
	adds r1, r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldr r3, _08109A30 @ =0x09993874
	movs r0, #0x00
	movs r2, #0x02
	bl func_0805FCB0
_081099EA:
	bl GetKeysPressed
	movs r1, #0x20
	ands r1, r0
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10
	cmp r4, #0x00
	beq _08109A38
	ldr r3, _08109A34 @ =0x02035FF0
	ldr r2, _08109A2C @ =0x02035FE8
	movs r1, #0x00
	ldsb r1, [r2, r1]
	lsls r1, r1, #0x01
	adds r1, r1, r3
	ldrh r0, [r1, #0x00]
	subs r0, #0x01
	strh r0, [r1, #0x00]
	lsls r0, r0, #0x10
	cmp r0, #0x00
	bge _08109A1E
	movs r0, #0x00
	ldsb r0, [r2, r0]
	lsls r0, r0, #0x01
	adds r0, r0, r3
	movs r1, #0x02
	strh r1, [r0, #0x00]
_08109A1E:
	bl func_081097F4
	b _08109A6C
_08109A24: .4byte 0x02035FE9
_08109A28: .4byte 0x09993888
_08109A2C: .4byte 0x02035FE8
_08109A30: .4byte 0x09993874
_08109A34: .4byte 0x02035FF0
_08109A38:
	bl GetKeysPressed
	movs r1, #0x10
	ands r1, r0
	cmp r1, #0x00
	beq _08109A6C
	ldr r3, _08109A84 @ =0x02035FF0
	ldr r2, _08109A88 @ =0x02035FE8
	movs r1, #0x00
	ldsb r1, [r2, r1]
	lsls r1, r1, #0x01
	adds r1, r1, r3
	ldrh r0, [r1, #0x00]
	adds r0, #0x01
	strh r0, [r1, #0x00]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x02
	ble _08109A68
	movs r0, #0x00
	ldsb r0, [r2, r0]
	lsls r0, r0, #0x01
	adds r0, r0, r3
	strh r4, [r0, #0x00]
_08109A68:
	bl func_081097F4
_08109A6C:
	bl GetKeysPressed
	movs r1, #0x0F
	ands r1, r0
	cmp r1, #0x00
	beq _08109A90
	ldr r0, _08109A8C @ =0x09ECEB64
	movs r1, #0x00
	bl func_080010CC
	b _08109A9A
	.byte 0x00, 0x00
_08109A84: .4byte 0x02035FF0
_08109A88: .4byte 0x02035FE8
_08109A8C: .4byte 0x09ECEB64
_08109A90:
	movs r0, #0x00
	bl func_080605A4
	bl func_08060598
_08109A9A:
	pop {r4, r5}
	pop {r0}
	bx r0
.syntax divided
