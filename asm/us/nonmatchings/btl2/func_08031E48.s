.syntax unified
	.align 2, 0
	.global func_08031E48
	.thumb
	.thumb_func
	.type func_08031E48, %function
func_08031E48: @ 08031E48
	push {r4, r5, r6, lr}
	add sp, #-0x020
	adds r5, r1, #0x0
	mov r2, sp
	adds r1, r0, #0x0
	ldm r1!, {r3, r4, r6}
	stm r2!, {r3, r4, r6}
	ldr r1, [r1, #0x00]
	str r1, [r2, #0x00]
	add r4, sp, #0x010
	adds r1, r4, #0x0
	ldm r0!, {r2, r3, r6}
	stm r1!, {r2, r3, r6}
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	ldr r0, [sp, #0x004]
	ldr r1, _08031E94 @ =0xFFFFFA00
	adds r0, r0, r1
	str r0, [sp, #0x004]
	ldr r0, [r4, #0x04]
	movs r2, #0xC0
	lsls r2, r2, #0x03
	adds r0, r0, r2
	str r0, [r4, #0x04]
	mov r0, sp
	bl _080DFE1C
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0x00
	beq _08031E98
	adds r1, r5, #0x0
	adds r1, #0xB0
	ldr r0, [sp, #0x000]
	str r0, [r1, #0x00]
	adds r1, #0x04
	ldr r0, [sp, #0x004]
	b _08031EB6
_08031E94: .4byte 0xFFFFFA00
_08031E98:
	adds r0, r4, #0x0
	bl _080DFE1C
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0x00
	bne _08031EAA
	movs r0, #0x00
	b _08031EBA
_08031EAA:
	adds r1, r5, #0x0
	adds r1, #0xB0
	ldr r0, [sp, #0x010]
	str r0, [r1, #0x00]
	adds r1, #0x04
	ldr r0, [r4, #0x04]
_08031EB6:
	str r0, [r1, #0x00]
	adds r0, r2, #0x0
_08031EBA:
	add sp, #0x020
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided
