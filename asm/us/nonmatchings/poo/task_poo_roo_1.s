.syntax unified
	.align 2, 0
	.global task_poo_roo_1
	.thumb
	.thumb_func
	.type task_poo_roo_1, %function
task_poo_roo_1: @ 080CEF04
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0x0
	adds r7, r5, #0x0
	adds r7, #0xB4
	ldr r0, [r7, #0x00]
	cmp r0, #0x01
	beq _080CEF74
	cmp r0, #0x01
	bcc _080CEF2A
	cmp r0, #0x02
	beq _080CEFD0
	cmp r0, #0x03
	bne _080CEF20
	b _080CF01E
_080CEF20:
	adds r6, r5, #0x0
	adds r6, #0x0C
	adds r4, r5, #0x0
	adds r4, #0x3C
	b _080CF03A
_080CEF2A:
	adds r4, r5, #0x0
	adds r4, #0x0C
	adds r0, r4, #0x0
	bl func_08005B1C
	lsls r0, r0, #0x18
	adds r6, r4, #0x0
	adds r4, #0x30
	cmp r0, #0x00
	bne _080CEF40
	b _080CF03A
_080CEF40:
	adds r0, r6, #0x0
	movs r1, #0x05
	movs r2, #0x00
	bl func_080059A4
	movs r0, #0x01
	str r0, [r7, #0x00]
	adds r1, r5, #0x0
	adds r1, #0x28
	ldr r0, [r5, #0x38]
	ldm r0!, {r2, r3, r7}
	stm r1!, {r2, r3, r7}
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	ldr r0, [r5, #0x28]
	ldr r1, _080CEF70 @ =0xFFFFFA00
	adds r0, r0, r1
	str r0, [r5, #0x28]
	ldr r0, [r5, #0x30]
	movs r2, #0xF8
	lsls r2, r2, #0x05
	adds r0, r0, r2
	str r0, [r5, #0x30]
	b _080CF03A
_080CEF70: .4byte 0xFFFFFA00
_080CEF74:
	adds r2, r5, #0x0
	adds r2, #0xB0
	ldr r0, [r5, #0x30]
	str r0, [r2, #0x00]
	adds r1, r5, #0x0
	adds r1, #0x28
	ldr r0, [r5, #0x38]
	ldm r0!, {r3, r4, r6}
	stm r1!, {r3, r4, r6}
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	ldr r0, [r5, #0x28]
	ldr r1, _080CEFC8 @ =0xFFFFFA00
	adds r0, r0, r1
	str r0, [r5, #0x28]
	ldr r0, [r5, #0x30]
	movs r3, #0xF8
	lsls r3, r3, #0x05
	adds r1, r0, r3
	str r1, [r5, #0x30]
	ldr r0, [r2, #0x00]
	subs r0, r0, r1
	adds r6, r5, #0x0
	adds r6, #0x0C
	adds r4, r5, #0x0
	adds r4, #0x3C
	cmp r0, #0x00
	bge _080CF03A
	ldr r0, _080CEFCC @ =0xFFFFDF00
	cmp r1, r0
	blt _080CF03A
	adds r0, r6, #0x0
	movs r1, #0x06
	movs r2, #0x00
	bl func_080059A4
	movs r0, #0x02
	str r0, [r7, #0x00]
	adds r1, r5, #0x0
	adds r1, #0xAC
	movs r0, #0x00
	b _080CF038
_080CEFC8: .4byte 0xFFFFFA00
_080CEFCC: .4byte 0xFFFFDF00
_080CEFD0:
	adds r2, r5, #0x0
	adds r2, #0xAC
	ldr r0, [r5, #0x30]
	ldr r1, [r2, #0x00]
	adds r0, r0, r1
	str r0, [r5, #0x30]
	ldr r0, [r2, #0x00]
	adds r0, #0x07
	str r0, [r2, #0x00]
	ldr r0, [r5, #0x30]
	cmp r0, #0x00
	blt _080CEFEE
	movs r0, #0x00
	str r0, [r5, #0x30]
	b _080CEFFA
_080CEFEE:
	ldr r0, [r5, #0x28]
	subs r0, #0x40
	str r0, [r5, #0x28]
	ldr r0, [r5, #0x2C]
	adds r0, #0x40
	str r0, [r5, #0x2C]
_080CEFFA:
	ldr r0, [r5, #0x38]
	ldr r0, [r0, #0x08]
	adds r6, r5, #0x0
	adds r6, #0x0C
	adds r4, r5, #0x0
	adds r4, #0x3C
	cmp r0, #0x00
	blt _080CF03A
	movs r0, #0x8B
	bl func_080C7B84
	movs r0, #0x05
	bl func_080D2D3C
	movs r0, #0x50
	bl func_0800FDD0
	b _080CF03A
_080CF01E:
	adds r4, r5, #0x0
	adds r4, #0x3C
	adds r0, r4, #0x0
	movs r1, #0x09
	bl func_08012660
	lsls r0, r0, #0x18
	adds r6, r5, #0x0
	adds r6, #0x0C
	cmp r0, #0x00
	beq _080CF03A
	ldr r1, _080CF060 @ =0x0203C3F0
	movs r0, #0x05
_080CF038:
	str r0, [r1, #0x00]
_080CF03A:
	adds r0, r6, #0x0
	bl func_08005A64
	str r0, [r5, #0x08]
	ldr r1, [r5, #0x28]
	ldr r2, [r5, #0x2C]
	ldr r3, [r5, #0x30]
	adds r0, r4, #0x0
	bl func_08012324
	adds r0, r5, #0x0
	adds r0, #0x98
	bl func_08000EA4
	movs r0, #0x01
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
_080CF060: .4byte 0x0203C3F0
.syntax divided
