.syntax unified
	.align 2, 0
	.global func_0801B918
	.thumb
	.thumb_func
	.type func_0801B918, %function
func_0801B918: @ 0801B918
	push {r4, lr}
	add sp, #-0x024
	ldr r1, [r0, #0x04]
	str r1, [sp, #0x000]
	ldr r1, [r0, #0x08]
	str r1, [sp, #0x004]
	ldr r1, [r0, #0x0C]
	str r1, [sp, #0x008]
	mov r2, sp
	movs r1, #0x01
	strh r1, [r2, #0x14]
	adds r0, #0xB4
	ldrh r0, [r0, #0x00]
	add r4, sp, #0x020
	strh r0, [r4, #0x00]
	movs r2, #0xAF
	lsls r2, r2, #0x03
	mov r0, sp
	movs r1, #0x00
	adds r3, r4, #0x0
	bl func_0801B8A8
	mov r0, sp
	movs r1, #0x08
	movs r2, #0xC7
	adds r3, r4, #0x0
	bl func_0801B8A8
	mov r0, sp
	movs r1, #0x05
	movs r2, #0x3C
	adds r3, r4, #0x0
	bl func_0801B8A8
	mov r0, sp
	movs r1, #0x07
	movs r2, #0x1E
	adds r3, r4, #0x0
	bl func_0801B8A8
	mov r0, sp
	movs r1, #0x04
	movs r2, #0x0A
	adds r3, r4, #0x0
	bl func_0801B8A8
	mov r0, sp
	movs r1, #0x06
	movs r2, #0x05
	adds r3, r4, #0x0
	bl func_0801B8A8
	mov r0, sp
	movs r1, #0x03
	movs r2, #0x01
	adds r3, r4, #0x0
	bl func_0801B8A8
	add sp, #0x024
	pop {r4}
	pop {r0}
	bx r0
.syntax divided
