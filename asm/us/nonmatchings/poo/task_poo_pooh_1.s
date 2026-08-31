.syntax unified
	.align 2, 0
	.global task_poo_pooh_1
	.thumb
	.thumb_func
	.type task_poo_pooh_1, %function
task_poo_pooh_1: @ 080C9974
	push {r4, r5, r6, lr}
	adds r5, r0, #0x0
	adds r0, #0x4C
	adds r1, r5, #0x0
	adds r1, #0x28
	adds r2, r5, #0x0
	adds r2, #0xE8
	bl func_080C8B38
	adds r1, r5, #0x0
	adds r1, #0xEC
	str r0, [r1, #0x00]
	bl func_080C8BD4
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080C999A
	movs r1, #0x00
	b _080C99A0
_080C999A:
	bl func_080CCC98
	adds r1, r0, #0x0
_080C99A0:
	adds r2, r5, #0x0
	adds r2, #0xFA
	movs r0, #0x00
	strb r0, [r2, #0x00]
	adds r0, r5, #0x0
	bl _080C8C40
	adds r0, r5, #0x0
	bl func_080C98B8
	ldr r4, _080C99F4 @ =0x02034DAC
	ldr r1, [r4, #0x00]
	adds r0, r5, #0x0
	bl _080C7FEC
	adds r6, r5, #0x0
	adds r6, #0x0C
	adds r0, r6, #0x0
	bl AnimUpdate
	str r0, [r5, #0x08]
	ldr r4, [r4, #0x00]
	cmp r4, #0x03
	beq _080C99D4
	cmp r4, #0x07
	bne _080C9A02
_080C99D4:
	ldrh r0, [r5, #0x16]
	cmp r0, #0x00
	bne _080C9A02
	adds r0, r6, #0x0
	bl func_08005B34
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x03
	beq _080C99FC
	cmp r0, #0x09
	bne _080C9A02
	ldr r0, _080C99F8 @ =0x0000039E
	bl m4aSongNumStart
	b _080C9A02
_080C99F4: .4byte 0x02034DAC
_080C99F8: .4byte 0x0000039E
_080C99FC:
	ldr r0, _080C9A20 @ =0x0000039F
	bl m4aSongNumStart
_080C9A02:
	adds r0, r5, #0x0
	adds r0, #0x4C
	ldr r1, [r5, #0x28]
	ldr r2, [r5, #0x2C]
	ldr r3, [r5, #0x30]
	bl func_08012324
	adds r0, r5, #0x0
	adds r0, #0xB0
	bl TaskPoolUpdate
	movs r0, #0x01
	pop {r4, r5, r6}
	pop {r1}
	bx r1
_080C9A20: .4byte 0x0000039F
.syntax divided
