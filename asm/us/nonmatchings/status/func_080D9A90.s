.syntax unified
	.align 2, 0
	.global func_080D9A90
	.thumb
	.thumb_func
	.type func_080D9A90, %function
func_080D9A90: @ 080D9A90
	push {r4, lr}
	ldr r4, _080D9AAC @ =0x02034F08
	ldr r0, [r4, #0x00]
	movs r1, #0xB0
	lsls r1, r1, #0x01
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	bl func_08000F48
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _080D9AB0
	movs r0, #0x0B
	b _080D9ABE
_080D9AAC: .4byte 0x02034F08
_080D9AB0:
	ldr r0, [r4, #0x00]
	movs r1, #0xB0
	lsls r1, r1, #0x01
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	ldr r0, [r0, #0x04]
	ldr r0, [r0, #0x00]
_080D9ABE:
	pop {r4}
	pop {r1}
	bx r1
.syntax divided
