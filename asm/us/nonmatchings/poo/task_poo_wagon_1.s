.syntax unified
	.align 2, 0
	.global task_poo_wagon_1
	.thumb
	.thumb_func
	.type task_poo_wagon_1, %function
task_poo_wagon_1: @ 080D0304
	push {r4, r5, lr}
	adds r4, r0, #0x0
	bl func_080CFF0C
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080D0324
	ldr r1, [r4, #0x20]
	ldr r0, [r4, #0x30]
	adds r5, r4, #0x0
	adds r5, #0x3C
	cmp r1, r0
	bne _080D035A
	movs r2, #0x80
	lsls r2, r2, #0x01
	b _080D033E
_080D0324:
	movs r0, #0x06
	bl func_080D2D50
	lsls r0, r0, #0x18
	adds r5, r4, #0x0
	adds r5, #0x3C
	cmp r0, #0x00
	bne _080D035A
	ldr r1, [r4, #0x20]
	ldr r0, [r4, #0x30]
	cmp r1, r0
	beq _080D035A
	ldr r2, _080D03F0 @ =0xFFFFFF00
_080D033E:
	adds r0, r1, r2
	str r0, [r4, #0x20]
	ldr r1, _080D03F4 @ =0x0203C420
	ldr r0, [r1, #0x04]
	adds r0, r0, r2
	str r0, [r1, #0x04]
	ldrb r0, [r5, #0x00]
	cmp r0, #0x00
	beq _080D035A
	ldr r0, _080D03F8 @ =0x0203C3EC
	ldr r1, [r0, #0x00]
	ldr r0, [r1, #0x04]
	adds r0, r0, r2
	str r0, [r1, #0x04]
_080D035A:
	ldr r0, _080D03F8 @ =0x0203C3EC
	ldr r0, [r0, #0x00]
	bl func_080CFEA0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x00
	beq _080D0384
	ldrb r0, [r5, #0x00]
	cmp r0, #0x00
	bne _080D0386
	ldr r1, _080D03FC @ =0x0203C3DC
	ldr r0, [r4, #0x1C]
	str r0, [r1, #0x00]
	ldr r1, _080D0400 @ =0x0203C3E8
	ldr r0, [r4, #0x20]
	str r0, [r1, #0x00]
	ldr r1, _080D0404 @ =0x0203C3F0
	movs r0, #0x0B
	str r0, [r1, #0x00]
	movs r0, #0x01
_080D0384:
	strb r0, [r5, #0x00]
_080D0386:
	bl func_080CFF0C
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080D040C
	bl func_080C9D98
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080D040C
	movs r0, #0x06
	bl func_080D2D50
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0x00
	bne _080D040C
	ldrh r0, [r4, #0x3E]
	adds r0, #0x01
	strh r0, [r4, #0x3E]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x64
	bls _080D0410
	ldr r3, [r4, #0x30]
	movs r1, #0xC0
	lsls r1, r1, #0x04
	adds r0, r3, r1
	ldr r2, [r4, #0x20]
	cmp r2, r0
	beq _080D0410
	ldr r0, _080D0408 @ =0xFFFFF400
	adds r1, r2, r0
	subs r1, r3, r1
	adds r0, r2, r1
	str r0, [r4, #0x20]
	ldr r2, _080D03F4 @ =0x0203C420
	ldr r0, [r2, #0x04]
	adds r0, r0, r1
	str r0, [r2, #0x04]
	ldr r0, _080D03F8 @ =0x0203C3EC
	ldr r2, [r0, #0x00]
	ldr r0, [r2, #0x04]
	adds r0, r0, r1
	str r0, [r2, #0x04]
	movs r0, #0x06
	bl func_080D2D3C
	movs r0, #0x90
	bl m4aSongNumStart
	strh r5, [r4, #0x3E]
	b _080D0410
_080D03F0: .4byte 0xFFFFFF00
_080D03F4: .4byte 0x0203C420
_080D03F8: .4byte 0x0203C3EC
_080D03FC: .4byte 0x0203C3DC
_080D0400: .4byte 0x0203C3E8
_080D0404: .4byte 0x0203C3F0
_080D0408: .4byte 0xFFFFF400
_080D040C:
	movs r0, #0x00
	strh r0, [r4, #0x3E]
_080D0410:
	movs r0, #0x01
	pop {r4, r5}
	pop {r1}
	bx r1
.syntax divided
