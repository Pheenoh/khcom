.syntax unified
	.align 2, 0
	.global mode_chkbtl_0
	.thumb
	.thumb_func
	.type mode_chkbtl_0, %function
mode_chkbtl_0: @ 0800A608
	push {r4, r5, lr}
	movs r0, #0x00
	movs r1, #0x08
	bl func_08006120
	bl func_08004DB0
	movs r0, #0x00
	movs r1, #0x00
	movs r2, #0x0F
	movs r3, #0x00
	bl SetupBg
	movs r0, #0x00
	bl func_08004FC8
	movs r1, #0xA8
	lsls r1, r1, #0x07
	movs r2, #0xA0
	lsls r2, r2, #0x03
	movs r0, #0x00
	bl func_0805FA8C
	ldr r1, _0800A6C4 @ =0x08128304
	movs r0, #0x00
	movs r2, #0x20
	movs r3, #0x0F
	bl func_0805FA60
	ldr r3, _0800A6C8 @ =0x08128324
	movs r0, #0x00
	movs r1, #0x00
	movs r2, #0x02
	bl func_0805FCB0
	ldr r3, _0800A6CC @ =0x0812834C
	movs r0, #0x18
	movs r1, #0x20
	movs r2, #0x02
	bl func_0805FCB0
	ldr r3, _0800A6D0 @ =0x08128358
	movs r0, #0x18
	movs r1, #0x2C
	movs r2, #0x02
	bl func_0805FCB0
	ldr r3, _0800A6D4 @ =0x08128364
	movs r0, #0x18
	movs r1, #0x38
	movs r2, #0x02
	bl func_0805FCB0
	ldr r3, _0800A6D8 @ =0x08128370
	movs r0, #0x18
	movs r1, #0x44
	movs r2, #0x02
	bl func_0805FCB0
	ldr r4, _0800A6DC @ =0x08126630
	ldr r5, _0800A6E0 @ =0x09ECEB50
	ldr r0, [r5, #0x00]
	movs r2, #0x02
	ldsh r1, [r0, r2]
	lsls r0, r1, #0x02
	adds r0, r0, r1
	lsls r0, r0, #0x02
	adds r1, r4, #0x0
	adds r1, #0x10
	adds r0, r0, r1
	ldr r3, [r0, #0x00]
	movs r0, #0x3E
	movs r1, #0x20
	movs r2, #0x02
	bl func_0805FCB0
	ldr r5, [r5, #0x00]
	movs r0, #0x02
	ldsh r1, [r5, r0]
	lsls r0, r1, #0x02
	adds r0, r0, r1
	lsls r0, r0, #0x02
	adds r4, #0x04
	adds r0, r0, r4
	ldr r0, [r0, #0x00]
	cmp r0, #0x02
	bne _0800A6E8
	ldr r3, _0800A6E4 @ =0x0812837C
	movs r0, #0x3E
	movs r1, #0x2C
	movs r2, #0x02
	bl func_0805FCB0
	b _0800A700
_0800A6C4: .4byte 0x08128304
_0800A6C8: .4byte 0x08128324
_0800A6CC: .4byte 0x0812834C
_0800A6D0: .4byte 0x08128358
_0800A6D4: .4byte 0x08128364
_0800A6D8: .4byte 0x08128370
_0800A6DC: .4byte 0x08126630
_0800A6E0: .4byte 0x09ECEB50
_0800A6E4: .4byte 0x0812837C
_0800A6E8:
	ldr r0, _0800A75C @ =0x08128234
	movs r1, #0x01
	ldsb r1, [r5, r1]
	lsls r1, r1, #0x03
	adds r0, #0x04
	adds r1, r1, r0
	ldr r3, [r1, #0x00]
	movs r0, #0x3E
	movs r1, #0x2C
	movs r2, #0x02
	bl func_0805FCB0
_0800A700:
	ldr r4, _0800A760 @ =0x09ECEB50
	ldr r0, [r4, #0x00]
	movs r3, #0x04
	ldsb r3, [r0, r3]
	adds r3, #0x01
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	movs r0, #0x3E
	movs r1, #0x38
	movs r2, #0x02
	bl func_0805FC04
	ldr r0, [r4, #0x00]
	ldrh r3, [r0, #0x06]
	movs r0, #0x3E
	movs r1, #0x44
	movs r2, #0x02
	bl func_0805FC04
	ldr r4, _0800A764 @ =0x03006C10
	ldr r0, [r4, #0x00]
	movs r5, #0x01
	ands r0, r5
	cmp r0, #0x00
	bne _0800A754
	bl func_08085FB0
	bl func_08085CB0
	ldr r1, _0800A768 @ =0x02039BB0
	adds r2, r1, #0x0
	adds r2, #0xFA
	ldr r0, _0800A76C @ =0x0000270F
	strh r0, [r2, #0x00]
	ldr r0, [r4, #0x00]
	orrs r0, r5
	str r0, [r4, #0x00]
	movs r2, #0xBE
	lsls r2, r2, #0x01
	adds r1, r1, r2
	ldr r0, _0800A770 @ =0x0000FFFF
	strh r0, [r1, #0x00]
_0800A754:
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0800A75C: .4byte 0x08128234
_0800A760: .4byte 0x09ECEB50
_0800A764: .4byte 0x03006C10
_0800A768: .4byte 0x02039BB0
_0800A76C: .4byte 0x0000270F
_0800A770: .4byte 0x0000FFFF
.syntax divided
