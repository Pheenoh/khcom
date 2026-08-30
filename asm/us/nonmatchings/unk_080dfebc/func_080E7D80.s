.syntax unified
	.align 2, 0
	.global func_080E7D80
	.thumb
	.thumb_func
	.type func_080E7D80, %function
func_080E7D80: @ 080E7D80
	push {r4, lr}
	adds r4, r0, #0x0
	movs r2, #0x00
	ldr r0, _080E7DA0 @ =0x02034F78
	ldrb r1, [r0, #0x00]
	cmp r2, r1
	bge _080E7DB0
	ldr r0, _080E7DA4 @ =0x0203C7B8
	adds r3, r1, #0x0
	ldr r1, [r0, #0x00]
_080E7D94:
	ldr r0, [r1, #0x14]
	ldr r0, [r0, #0x00]
	cmp r0, r4
	bne _080E7DA8
	movs r0, #0x00
	b _080E7DB2
_080E7DA0: .4byte 0x02034F78
_080E7DA4: .4byte 0x0203C7B8
_080E7DA8:
	adds r1, #0x18
	adds r2, #0x01
	cmp r2, r3
	blt _080E7D94
_080E7DB0:
	movs r0, #0x01
_080E7DB2:
	pop {r4}
	pop {r1}
	bx r1
.syntax divided
