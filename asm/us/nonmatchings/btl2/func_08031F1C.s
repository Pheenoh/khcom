.syntax unified
	.align 2, 0
	.global func_08031F1C
	.thumb
	.thumb_func
	.type func_08031F1C, %function
func_08031F1C: @ 08031F1C
	push {r4, lr}
	adds r2, r0, #0x0
	ldr r0, _08031F4C @ =0x02039BA0
	ldr r0, [r0, #0x00]
	adds r3, r0, #0x0
	adds r3, #0x18
	adds r0, r2, #0x0
	adds r0, #0x66
	ldrh r0, [r0, #0x00]
	movs r4, #0x01
	adds r1, r4, #0x0
	ands r1, r0
	cmp r1, #0x00
	beq _08031F50
	ldr r0, [r3, #0x0C]
	ldr r1, [r2, #0x78]
	cmp r0, r1
	bge _08031F42
	adds r1, r0, #0x0
_08031F42:
	adds r0, r2, #0x0
	adds r0, #0xBC
	strb r4, [r0, #0x00]
	b _08031F58
	.byte 0x00, 0x00
_08031F4C: .4byte 0x02039BA0
_08031F50:
	adds r0, r2, #0x0
	adds r0, #0xBC
	strb r1, [r0, #0x00]
	ldr r1, [r3, #0x0C]
_08031F58:
	adds r0, r1, #0x0
	pop {r4}
	pop {r1}
	bx r1
.syntax divided
