.syntax unified
	.align 2, 0
	.global task_bos_boogie_knifereader_1
	.thumb
	.thumb_func
	.type task_bos_boogie_knifereader_1, %function
task_bos_boogie_knifereader_1: @ 080DB578
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0x0
	adds r4, r5, #0x0
	adds r4, #0x1C
	adds r0, r4, #0x0
	bl func_0801ADAC
	subs r0, #0x01
	cmp r0, #0x07
	bhi _080DB5C2
	lsls r0, r0, #0x02
	ldr r1, _080DB598 @ =0x080DB59C
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	mov pc, r0
	.byte 0x00, 0x00
_080DB598: .4byte 0x080DB59C
	.byte 0xD2, 0xB5, 0x0D, 0x08, 0xC2, 0xB5, 0x0D, 0x08, 0xD2, 0xB5, 0x0D, 0x08, 0xD2, 0xB5, 0x0D, 0x08
	.byte 0xBC, 0xB5, 0x0D, 0x08, 0xD2, 0xB5, 0x0D, 0x08, 0xD2, 0xB5, 0x0D, 0x08, 0xD2, 0xB5, 0x0D, 0x08
	.byte 0x00, 0x20, 0x28, 0x60, 0x0D, 0xE0
_080DB5C2:
	movs r0, #0x00
	bl func_0801C1C0
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080DB5E0
	bl func_080D9A58
	ldr r0, [r5, #0x00]
	cmp r0, #0x01
	beq _080DB5E0
	movs r0, #0x01
	str r0, [r5, #0x00]
	movs r0, #0x00
	strh r0, [r5, #0x04]
_080DB5E0:
	ldr r1, [r5, #0x00]
	cmp r1, #0x01
	beq _080DB602
	cmp r1, #0x01
	bcc _080DB60C
	cmp r1, #0x02
	bne _080DB626
	ldrh r1, [r5, #0x04]
	movs r2, #0x04
	ldsh r0, [r5, r2]
	cmp r0, #0x1E
	ble _080DB5FC
	movs r0, #0x00
	b _080DB67E
_080DB5FC:
	adds r0, r1, #0x1
	strh r0, [r5, #0x04]
	b _080DB620
_080DB602:
	ldr r0, _080DB608 @ =0x0203C574
	strb r1, [r0, #0x00]
	b _080DB626
_080DB608: .4byte 0x0203C574
_080DB60C:
	ldrh r1, [r5, #0x04]
	movs r2, #0x04
	ldsh r0, [r5, r2]
	cmp r0, #0x00
	bne _080DB626
	adds r0, r1, #0x1
	strh r0, [r5, #0x04]
	adds r0, r5, #0x0
	bl func_080DB468
_080DB620:
	adds r7, r5, #0x0
	adds r7, #0x08
	b _080DB676
_080DB626:
	adds r0, r5, #0x0
	bl func_080DB438
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _080DB63C
	adds r0, r4, #0x0
	bl func_0801AF08
	movs r0, #0x00
	b _080DB67E
_080DB63C:
	movs r6, #0x00
	adds r7, r5, #0x0
	adds r7, #0x08
_080DB642:
	lsls r1, r6, #0x02
	movs r2, #0x96
	lsls r2, r2, #0x01
	adds r0, r5, r2
	adds r4, r0, r1
	ldr r0, [r4, #0x00]
	bl func_08000F48
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080DB670
	ldr r0, [r4, #0x00]
	ldr r0, [r0, #0x04]
	bl func_080DB428
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080DB676
	movs r0, #0x95
	lsls r0, r0, #0x02
	bl m4aSongNumStart
	b _080DB676
_080DB670:
	adds r6, #0x01
	cmp r6, #0x04
	ble _080DB642
_080DB676:
	adds r0, r7, #0x0
	bl TaskPoolUpdate
	movs r0, #0x01
_080DB67E:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
.syntax divided
