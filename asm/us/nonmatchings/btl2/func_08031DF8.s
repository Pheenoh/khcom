.syntax unified
	.align 2, 0
	.global func_08031DF8
	.thumb
	.thumb_func
	.type func_08031DF8, %function
func_08031DF8: @ 08031DF8
	push {r4, r5, lr}
	add sp, #-0x020
	mov r2, sp
	adds r1, r0, #0x0
	ldm r1!, {r3, r4, r5}
	stm r2!, {r3, r4, r5}
	ldr r1, [r1, #0x00]
	str r1, [r2, #0x00]
	add r4, sp, #0x010
	adds r1, r4, #0x0
	ldm r0!, {r2, r3, r5}
	stm r1!, {r2, r3, r5}
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	ldr r0, [sp, #0x004]
	ldr r1, _08031E44 @ =0xFFFFFA00
	adds r0, r0, r1
	str r0, [sp, #0x004]
	ldr r0, [r4, #0x04]
	movs r2, #0xC0
	lsls r2, r2, #0x03
	adds r0, r0, r2
	str r0, [r4, #0x04]
	mov r0, sp
	bl func_080DFF1C
	adds r5, r0, #0x0
	adds r0, r4, #0x0
	bl func_080DFF1C
	cmp r0, r5
	ble _08031E3A
	adds r0, r5, #0x0
_08031E3A:
	add sp, #0x020
	pop {r4, r5}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
_08031E44: .4byte 0xFFFFFA00
.syntax divided
