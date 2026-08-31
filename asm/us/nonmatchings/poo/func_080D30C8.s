.syntax unified
	.align 2, 0
	.global func_080D30C8
	.thumb
	.thumb_func
	.type func_080D30C8, %function
func_080D30C8: @ 080D30C8
	push {r4, r5, r6, lr}
	ldr r5, _080D3130 @ =0x096FDA8C
	ldr r6, _080D3134 @ =0x02039BB0
	ldrb r1, [r6, #0x0C]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x02
	adds r0, r0, r5
	ldr r4, [r0, #0x00]
	movs r0, #0x02
	bl GetBgScreenBase
	adds r1, r0, #0x0
	movs r0, #0x80
	lsls r0, r0, #0x02
	adds r1, r1, r0
	movs r2, #0xC0
	lsls r2, r2, #0x02
	adds r0, r4, #0x0
	bl RequestDma3Copy
	ldrb r1, [r6, #0x0C]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x02
	adds r1, r5, #0x4
	adds r0, r0, r1
	ldr r4, [r0, #0x00]
	movs r0, #0x02
	bl GetBgCharBase
	adds r1, r0, #0x0
	movs r2, #0x80
	lsls r2, r2, #0x06
	adds r1, r1, r2
	adds r0, r4, #0x0
	bl RequestDma3Copy
	ldrb r1, [r6, #0x0C]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x02
	adds r5, #0x08
	adds r0, r0, r5
	ldr r0, [r0, #0x00]
	ldr r1, _080D3138 @ =0x05000140
	movs r2, #0x20
	bl LoadPalette
	pop {r4, r5, r6}
	pop {r0}
	bx r0
_080D3130: .4byte 0x096FDA8C
_080D3134: .4byte 0x02039BB0
_080D3138: .4byte 0x05000140
.syntax divided
