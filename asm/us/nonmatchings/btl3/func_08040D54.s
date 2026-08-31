.syntax unified
	.align 2, 0
	.global func_08040D54
	.thumb
	.thumb_func
	.type func_08040D54, %function
func_08040D54: @ 08040D54
	push {r4, r5, r6, lr}
	add sp, #-0x028
	adds r5, r0, #0x0
	ldr r0, _08040D84 @ =0x02039B84
	ldr r3, [r0, #0x00]
	ldr r0, [r3, #0x68]
	ldr r1, [r3, #0x6C]
	movs r2, #0x80
	lsls r2, r2, #0x07
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _08040D9C
	ldr r1, _08040D88 @ =0x00000163
	adds r0, r5, r1
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08040D90
	ldr r0, _08040D8C @ =0x02039B9C
	ldr r0, [r0, #0x00]
	ldr r3, [r0, #0x7C]
	b _08040D92
	.byte 0x00, 0x00
_08040D84: .4byte 0x02039B84
_08040D88: .4byte 0x00000163
_08040D8C: .4byte 0x02039B9C
_08040D90:
	ldr r3, [r3, #0x7C]
_08040D92:
	movs r2, #0x2C
	ldsh r0, [r3, r2]
	cmp r0, #0x00
	ble _08040E1C
	b _08040E18
_08040D9C:
	movs r4, #0x00
	adds r0, r3, #0x0
	adds r0, #0x80
	bl func_08000C8C
	adds r3, r0, #0x0
	cmp r3, #0x00
	beq _08040DFC
	movs r6, #0xC0
	lsls r6, r6, #0x06
_08040DB0:
	ldr r0, [r3, #0x34]
	ldr r1, [r3, #0x38]
	movs r2, #0x80
	lsls r2, r2, #0x11
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	bne _08040DEE
	ldr r2, [r5, #0x44]
	ldr r0, [r3, #0x0C]
	subs r1, r2, r0
	cmp r1, #0x00
	blt _08040DD2
	cmp r1, r6
	ble _08040DD8
	b _08040DEE
_08040DD2:
	subs r0, r0, r2
	cmp r0, r6
	bgt _08040DEE
_08040DD8:
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	lsls r1, r0, #0x02
	add r1, sp
	str r3, [r1, #0x00]
	adds r0, #0x01
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x09
	bgt _08040DFC
_08040DEE:
	adds r0, r3, #0x0
	adds r0, #0xB8
	bl func_08000CD4
	adds r3, r0, #0x0
	cmp r3, #0x00
	bne _08040DB0
_08040DFC:
	lsls r0, r4, #0x10
	asrs r4, r0, #0x10
	cmp r4, #0x00
	beq _08040E1C
	bl GetRandom
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r1, r4, #0x0
	bl __modsi3
	lsls r0, r0, #0x02
	add r0, sp
	ldr r3, [r0, #0x00]
_08040E18:
	adds r0, r3, #0x0
	b _08040E1E
_08040E1C:
	movs r0, #0x00
_08040E1E:
	add sp, #0x028
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided
