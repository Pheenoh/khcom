.syntax unified
	.align 2, 0
	.global task_btl_premire_1
	.thumb
	.thumb_func
	.type task_btl_premire_1, %function
task_btl_premire_1: @ 0803150C
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0x0
	ldr r6, _08031594 @ =0x02039B84
	ldr r3, [r6, #0x00]
	ldr r0, [r3, #0x68]
	ldr r1, [r3, #0x6C]
	movs r2, #0x80
	lsls r2, r2, #0x06
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _0803152E
	b _08031938
_0803152E:
	ldr r0, [r7, #0x30]
	cmp r0, #0x00
	beq _08031536
	b _08031950
_08031536:
	ldrh r1, [r7, #0x2C]
	movs r0, #0x04
	ands r0, r1
	cmp r0, #0x00
	bne _080315EC
	movs r1, #0x94
	lsls r1, r1, #0x01
	adds r0, r3, r1
	ldr r4, [r0, #0x00]
	adds r5, r7, #0x4
	cmp r4, #0x00
	beq _0803155E
	adds r2, r7, #0x0
	adds r2, #0x08
	adds r3, r7, #0x0
	adds r3, #0x0C
	adds r0, r7, #0x0
	adds r1, r5, #0x0
	bl _call_via_r4
_0803155E:
	ldr r0, [r7, #0x08]
	ldr r1, [r7, #0x20]
	adds r0, r0, r1
	str r0, [r7, #0x08]
	subs r1, #0x0F
	ldr r0, [r6, #0x00]
	movs r2, #0x96
	lsls r2, r2, #0x01
	adds r0, r0, r2
	ldr r0, [r0, #0x00]
	adds r1, r1, r0
	str r1, [r7, #0x20]
	adds r0, r7, #0x0
	adds r1, r5, #0x0
	movs r2, #0x00
	movs r3, #0x00
	bl func_0801A8A4
	cmp r0, #0x01
	bcc _080315A2
	cmp r0, #0x02
	bhi _08031598
	ldr r0, [r7, #0x38]
	negs r0, r0
	str r0, [r7, #0x38]
	b _080315A2
	.byte 0x00, 0x00
_08031594: .4byte 0x02039B84
_08031598:
	cmp r0, #0x04
	bhi _080315A2
	ldr r0, [r7, #0x3C]
	negs r0, r0
	str r0, [r7, #0x3C]
_080315A2:
	ldr r0, [r7, #0x00]
	ldr r1, [r7, #0x38]
	adds r0, r0, r1
	str r0, [r7, #0x00]
	ldr r0, [r7, #0x04]
	ldr r1, [r7, #0x3C]
	adds r0, r0, r1
	str r0, [r7, #0x04]
	ldr r0, [r7, #0x08]
	ldr r2, [r7, #0x0C]
	cmp r0, r2
	ble _080315E4
	ldrh r1, [r7, #0x2C]
	ldr r0, _080315E0 @ =0x0000FFFD
	ands r0, r1
	strh r0, [r7, #0x2C]
	str r2, [r7, #0x08]
	bl func_080065A4
	ldr r1, [r7, #0x24]
	asrs r4, r1, #0x01
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	subs r1, r1, r4
	adds r1, #0x01
	bl __modsi3
	adds r4, r4, r0
	negs r4, r4
	str r4, [r7, #0x20]
	b _080315EC
_080315E0: .4byte 0x0000FFFD
_080315E4:
	ldrh r1, [r7, #0x2C]
	movs r0, #0x02
	orrs r0, r1
	strh r0, [r7, #0x2C]
_080315EC:
	ldrh r1, [r7, #0x2C]
	movs r0, #0x10
	ands r0, r1
	mov r12, r1
	cmp r0, #0x00
	bne _080315FA
	b _0803193C
_080315FA:
	movs r0, #0x00
	mov r9, r0
	ldr r3, _0803165C @ =0x02039B84
	ldr r6, [r3, #0x00]
	ldr r4, [r6, #0x68]
	ldr r5, [r6, #0x6C]
	movs r2, #0x80
	lsls r2, r2, #0x07
	adds r0, r4, #0x0
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	mov r8, r3
	cmp r0, #0x00
	bne _0803161A
	b _08031824
_0803161A:
	movs r0, #0x80
	lsls r0, r0, #0x05
	adds r1, r4, #0x0
	ands r1, r0
	movs r2, #0x00
	adds r0, r2, #0x0
	orrs r0, r1
	cmp r0, #0x00
	bne _0803162E
	b _08031730
_0803162E:
	ldr r0, _08031660 @ =0x02039B9C
	ldr r2, [r0, #0x00]
	adds r1, r2, #0x0
	adds r1, #0xF4
	ldr r1, [r1, #0x00]
	movs r4, #0x80
	lsls r4, r4, #0x06
	adds r6, r0, #0x0
	cmp r1, #0x06
	bne _08031646
	movs r4, #0x80
	lsls r4, r4, #0x09
_08031646:
	ldr r0, [r2, #0x7C]
	ldr r1, [r0, #0x04]
	ldr r0, [r7, #0x00]
	subs r2, r1, r0
	adds r5, r0, #0x0
	cmp r2, #0x00
	blt _08031664
	cmp r2, r4
	blt _0803166A
	b _080316AE
	.byte 0x00, 0x00
_0803165C: .4byte 0x02039B84
_08031660: .4byte 0x02039B9C
_08031664:
	subs r0, r5, r1
	cmp r0, r4
	bge _080316AE
_0803166A:
	asrs r4, r4, #0x01
	ldr r0, [r6, #0x00]
	ldr r0, [r0, #0x7C]
	ldr r2, [r0, #0x08]
	ldr r0, [r7, #0x04]
	subs r1, r2, r0
	cmp r1, #0x00
	blt _08031680
	cmp r1, r4
	blt _08031686
	b _080316AE
_08031680:
	subs r0, r0, r2
	cmp r0, r4
	bge _080316AE
_08031686:
	ldr r0, [r6, #0x00]
	ldr r0, [r0, #0x7C]
	ldr r0, [r0, #0x0C]
	ldr r1, [r7, #0x08]
	subs r2, r0, r1
	cmp r2, #0x00
	blt _080316A4
	ldr r0, _080316A0 @ =0x000031FF
	cmp r2, r0
	bgt _0803169C
	b _08031818
_0803169C:
	b _080316AE
	.byte 0x00, 0x00
_080316A0: .4byte 0x000031FF
_080316A4:
	subs r1, r1, r0
	ldr r0, _080316D4 @ =0x000031FF
	cmp r1, r0
	bgt _080316AE
	b _08031818
_080316AE:
	mov r2, r8
	ldr r1, [r2, #0x00]
	adds r0, r1, #0x0
	adds r0, #0xF4
	ldr r0, [r0, #0x00]
	movs r4, #0x80
	lsls r4, r4, #0x06
	cmp r0, #0x06
	bne _080316C4
	movs r4, #0x80
	lsls r4, r4, #0x09
_080316C4:
	ldr r0, [r1, #0x7C]
	ldr r0, [r0, #0x04]
	subs r1, r0, r5
	cmp r1, #0x00
	blt _080316D8
	cmp r1, r4
	blt _080316E0
	b _08031894
_080316D4: .4byte 0x000031FF
_080316D8:
	subs r0, r5, r0
	cmp r0, r4
	blt _080316E0
	b _08031894
_080316E0:
	asrs r4, r4, #0x01
	mov r1, r8
	ldr r0, [r1, #0x00]
	ldr r0, [r0, #0x7C]
	ldr r2, [r0, #0x08]
	ldr r0, [r7, #0x04]
	subs r1, r2, r0
	cmp r1, #0x00
	blt _080316F8
	cmp r1, r4
	blt _08031700
	b _08031894
_080316F8:
	subs r0, r0, r2
	cmp r0, r4
	blt _08031700
	b _08031894
_08031700:
	mov r2, r8
	ldr r0, [r2, #0x00]
	ldr r0, [r0, #0x7C]
	ldr r0, [r0, #0x0C]
	ldr r1, [r7, #0x08]
	subs r2, r0, r1
	cmp r2, #0x00
	blt _08031720
	ldr r0, _0803171C @ =0x000031FF
	cmp r2, r0
	bgt _08031718
	b _0803189A
_08031718:
	b _08031894
	.byte 0x00, 0x00
_0803171C: .4byte 0x000031FF
_08031720:
	subs r1, r1, r0
	ldr r0, _0803172C @ =0x000031FF
	cmp r1, r0
	ble _0803172A
	b _08031894
_0803172A:
	b _0803189A
_0803172C: .4byte 0x000031FF
_08031730:
	adds r0, r6, #0x0
	adds r0, #0xF4
	ldr r0, [r0, #0x00]
	movs r4, #0x80
	lsls r4, r4, #0x06
	cmp r0, #0x06
	bne _08031742
	movs r4, #0x80
	lsls r4, r4, #0x09
_08031742:
	ldr r0, [r6, #0x7C]
	ldr r3, [r0, #0x04]
	ldr r0, [r7, #0x00]
	subs r1, r3, r0
	adds r5, r0, #0x0
	cmp r1, #0x00
	blt _08031756
	cmp r1, r4
	blt _0803175C
	b _080317A2
_08031756:
	subs r0, r5, r3
	cmp r0, r4
	bge _080317A2
_0803175C:
	asrs r4, r4, #0x01
	mov r1, r8
	ldr r0, [r1, #0x00]
	ldr r0, [r0, #0x7C]
	ldr r2, [r0, #0x08]
	ldr r0, [r7, #0x04]
	subs r1, r2, r0
	cmp r1, #0x00
	blt _08031774
	cmp r1, r4
	blt _0803177A
	b _080317A2
_08031774:
	subs r0, r0, r2
	cmp r0, r4
	bge _080317A2
_0803177A:
	mov r2, r8
	ldr r0, [r2, #0x00]
	ldr r0, [r0, #0x7C]
	ldr r0, [r0, #0x0C]
	ldr r1, [r7, #0x08]
	subs r2, r0, r1
	cmp r2, #0x00
	blt _08031798
	ldr r0, _08031794 @ =0x000031FF
	cmp r2, r0
	bgt _08031792
	b _0803189A
_08031792:
	b _080317A2
_08031794: .4byte 0x000031FF
_08031798:
	subs r1, r1, r0
	ldr r0, _080317CC @ =0x000031FF
	cmp r1, r0
	bgt _080317A2
	b _0803189A
_080317A2:
	ldr r0, _080317D0 @ =0x02039B9C
	ldr r2, [r0, #0x00]
	adds r1, r2, #0x0
	adds r1, #0xF4
	ldr r1, [r1, #0x00]
	movs r4, #0x80
	lsls r4, r4, #0x06
	adds r6, r0, #0x0
	cmp r1, #0x06
	bne _080317BA
	movs r4, #0x80
	lsls r4, r4, #0x09
_080317BA:
	ldr r0, [r2, #0x7C]
	ldr r0, [r0, #0x04]
	subs r2, r0, r5
	cmp r2, #0x00
	blt _080317D4
	cmp r2, r4
	blt _080317DA
	b _08031894
	.byte 0x00, 0x00
_080317CC: .4byte 0x000031FF
_080317D0: .4byte 0x02039B9C
_080317D4:
	subs r0, r5, r0
	cmp r0, r4
	bge _08031894
_080317DA:
	asrs r3, r4, #0x01
	ldr r0, [r6, #0x00]
	ldr r0, [r0, #0x7C]
	ldr r2, [r0, #0x08]
	ldr r0, [r7, #0x04]
	subs r1, r2, r0
	cmp r1, #0x00
	blt _080317F0
	cmp r1, r3
	blt _080317F6
	b _08031894
_080317F0:
	subs r0, r0, r2
	cmp r0, r3
	bge _08031894
_080317F6:
	ldr r0, [r6, #0x00]
	ldr r0, [r0, #0x7C]
	ldr r0, [r0, #0x0C]
	ldr r1, [r7, #0x08]
	subs r2, r0, r1
	cmp r2, #0x00
	blt _08031810
	ldr r0, _0803180C @ =0x000031FF
	cmp r2, r0
	ble _08031818
	b _08031894
_0803180C: .4byte 0x000031FF
_08031810:
	subs r1, r1, r0
	ldr r0, _08031820 @ =0x000031FF
	cmp r1, r0
	bgt _08031894
_08031818:
	ldr r0, [r6, #0x00]
	ldr r0, [r0, #0x7C]
	str r0, [r7, #0x44]
	b _0803189A
_08031820: .4byte 0x000031FF
_08031824:
	adds r0, r6, #0x0
	adds r0, #0xF4
	ldr r0, [r0, #0x00]
	movs r4, #0x80
	lsls r4, r4, #0x06
	cmp r0, #0x06
	bne _08031836
	movs r4, #0x80
	lsls r4, r4, #0x09
_08031836:
	ldr r0, [r6, #0x7C]
	ldr r3, [r0, #0x04]
	ldr r0, [r7, #0x00]
	subs r1, r3, r0
	cmp r1, #0x00
	blt _08031848
	cmp r1, r4
	blt _0803184E
	b _08031894
_08031848:
	subs r0, r0, r3
	cmp r0, r4
	bge _08031894
_0803184E:
	asrs r4, r4, #0x01
	mov r1, r8
	ldr r0, [r1, #0x00]
	ldr r0, [r0, #0x7C]
	ldr r2, [r0, #0x08]
	ldr r0, [r7, #0x04]
	subs r1, r2, r0
	cmp r1, #0x00
	blt _08031866
	cmp r1, r4
	blt _0803186C
	b _08031894
_08031866:
	subs r0, r0, r2
	cmp r0, r4
	bge _08031894
_0803186C:
	mov r2, r8
	ldr r0, [r2, #0x00]
	ldr r0, [r0, #0x7C]
	ldr r0, [r0, #0x0C]
	ldr r1, [r7, #0x08]
	subs r2, r0, r1
	cmp r2, #0x00
	blt _08031888
	ldr r0, _08031884 @ =0x000031FF
	cmp r2, r0
	ble _08031890
	b _08031894
_08031884: .4byte 0x000031FF
_08031888:
	subs r1, r1, r0
	ldr r0, _080318F4 @ =0x000031FF
	cmp r1, r0
	bgt _08031894
_08031890:
	movs r0, #0x01
	mov r9, r0
_08031894:
	mov r1, r9
	cmp r1, #0x00
	beq _08031908
_0803189A:
	movs r0, #0x6B
	bl func_0811FE70
	ldr r0, _080318F8 @ =0x02039B84
	ldr r4, [r0, #0x00]
	ldr r0, [r4, #0x68]
	ldr r1, [r4, #0x6C]
	ldr r2, _080318FC @ =0x00000000
	ldr r3, _08031900 @ =0x00080000
	orrs r1, r3
	str r0, [r4, #0x68]
	str r1, [r4, #0x6C]
	movs r1, #0x00
	movs r0, #0x01
	str r0, [r7, #0x30]
	strh r1, [r7, #0x28]
	ldr r1, [r7, #0x44]
	ldr r0, [r1, #0x04]
	ldr r1, [r1, #0x08]
	ldr r2, [r7, #0x00]
	ldr r3, [r7, #0x04]
	bl func_0801CB6C
	adds r1, r7, #0x0
	adds r1, #0x40
	strb r0, [r1, #0x00]
	ldrh r1, [r7, #0x2C]
	ldr r0, _08031904 @ =0x0000FFFD
	ands r0, r1
	movs r1, #0x01
	orrs r0, r1
	strh r0, [r7, #0x2C]
	bl func_080065A4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x06
	bl __umodsi3
	adds r0, #0x05
	adds r1, r7, #0x0
	adds r1, #0x2A
	strb r0, [r1, #0x00]
	b _080319D2
	.byte 0x00, 0x00
_080318F4: .4byte 0x000031FF
_080318F8: .4byte 0x02039B84
_080318FC: .4byte 0x00000000
_08031900: .4byte 0x00080000
_08031904: .4byte 0x0000FFFD
_08031908:
	movs r0, #0x08
	mov r2, r12
	ands r0, r2
	ldrh r2, [r7, #0x28]
	cmp r0, #0x00
	bne _0803194C
	lsls r1, r2, #0x10
	movs r0, #0xB4
	lsls r0, r0, #0x11
	cmp r1, r0
	ble _0803192E
	movs r0, #0x03
	ands r0, r2
	cmp r0, #0x00
	bne _0803192E
	movs r0, #0x01
	mov r1, r12
	eors r0, r1
	strh r0, [r7, #0x2C]
_0803192E:
	lsls r1, r2, #0x10
	movs r0, #0xD2
	lsls r0, r0, #0x11
	cmp r1, r0
	ble _0803194C
_08031938:
	movs r0, #0x00
	b _080319DE
_0803193C:
	movs r2, #0x28
	ldsh r0, [r7, r2]
	ldrh r2, [r7, #0x28]
	cmp r0, #0x0A
	ble _0803194C
	movs r0, #0x10
	orrs r0, r1
	strh r0, [r7, #0x2C]
_0803194C:
	adds r0, r2, #0x1
	b _080319D0
_08031950:
	ldr r5, [r7, #0x44]
	ldr r6, _080319EC @ =0x08121400
	movs r0, #0x40
	adds r0, r0, r7
	mov r8, r0
	ldrb r4, [r0, #0x00]
	lsls r0, r4, #0x01
	adds r0, r0, r6
	movs r1, #0x00
	ldsh r2, [r0, r1]
	ldr r1, [r7, #0x34]
	lsls r0, r1, #0x05
	muls r0, r2
	asrs r0, r0, #0x08
	ldr r3, [r5, #0x04]
	adds r3, r3, r0
	adds r0, r4, #0x0
	adds r0, #0x40
	lsls r0, r0, #0x01
	adds r0, r0, r6
	movs r2, #0x00
	ldsh r0, [r0, r2]
	negs r0, r0
	lsls r1, r1, #0x04
	muls r0, r1
	asrs r0, r0, #0x08
	ldr r2, [r5, #0x08]
	adds r2, r2, r0
	ldrh r0, [r7, #0x28]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x11
	lsls r0, r0, #0x08
	ldr r1, [r5, #0x0C]
	subs r1, r1, r0
	adds r0, r7, #0x0
	adds r0, #0x2A
	ldrb r0, [r0, #0x00]
	adds r4, r4, r0
	mov r0, r8
	strb r4, [r0, #0x00]
	ldr r0, [r7, #0x00]
	subs r3, r3, r0
	asrs r3, r3, #0x02
	adds r0, r0, r3
	str r0, [r7, #0x00]
	ldr r0, [r7, #0x04]
	subs r2, r2, r0
	asrs r2, r2, #0x02
	adds r0, r0, r2
	str r0, [r7, #0x04]
	ldr r0, [r7, #0x08]
	subs r1, r1, r0
	asrs r1, r1, #0x02
	adds r0, r0, r1
	str r0, [r7, #0x08]
	ldr r0, [r7, #0x34]
	subs r0, #0x02
	str r0, [r7, #0x34]
	ldrh r1, [r7, #0x28]
	movs r2, #0x28
	ldsh r0, [r7, r2]
	cmp r0, #0x3C
	bgt _08031938
	adds r0, r1, #0x1
_080319D0:
	strh r0, [r7, #0x28]
_080319D2:
	adds r0, r7, #0x0
	adds r0, #0x48
	bl func_08005A64
	str r0, [r7, #0x18]
	movs r0, #0x01
_080319DE:
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
_080319EC: .4byte 0x08121400
.syntax divided
