.syntax unified
	.align 2, 0
	.global func_08104B48
	.thumb
	.thumb_func
	.type func_08104B48, %function
func_08104B48: @ 08104B48
	push {r4, r5, r6, lr}
	bl func_08104B2C
	adds r1, r0, #0x0
	ldrh r0, [r1, #0x00]
	cmp r0, #0x8F
	beq _08104BA4
	movs r4, #0x00
	movs r2, #0x06
	ldsh r0, [r1, r2]
	ldr r5, _08104B9C @ =0x02035E0C
	ldr r6, _08104BA0 @ =0x02035E0E
	cmp r0, #0x00
	bgt _08104B82
	adds r1, #0x06
_08104B66:
	lsls r0, r4, #0x10
	movs r2, #0x80
	lsls r2, r2, #0x09
	adds r0, r0, r2
	lsrs r4, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x09
	bgt _08104B82
	lsls r0, r0, #0x02
	adds r0, r1, r0
	movs r2, #0x00
	ldsh r0, [r0, r2]
	cmp r0, #0x00
	ble _08104B66
_08104B82:
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	adds r0, r4, #0x0
	movs r1, #0x05
	bl func_0811D5EC
	strh r0, [r5, #0x00]
	adds r0, r4, #0x0
	movs r1, #0x05
	bl func_0811D684
	strh r0, [r6, #0x00]
	b _08104BAE
_08104B9C: .4byte 0x02035E0C
_08104BA0: .4byte 0x02035E0E
_08104BA4:
	ldr r0, _08104BB4 @ =0x02035E0C
	movs r1, #0x00
	strh r1, [r0, #0x00]
	ldr r0, _08104BB8 @ =0x02035E0E
	strh r1, [r0, #0x00]
_08104BAE:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
_08104BB4: .4byte 0x02035E0C
_08104BB8: .4byte 0x02035E0E
.syntax divided
