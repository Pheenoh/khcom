.syntax unified
	.align 2, 0
	.global func_080C57B4
	.thumb
	.thumb_func
	.type func_080C57B4, %function
func_080C57B4: @ 080C57B4
	push {r4, lr}
	ldr r4, _080C57F8 @ =0x03006C78
	ldrh r1, [r4, #0x00]
	movs r0, #0x01
	ands r0, r1
	cmp r0, #0x00
	beq _080C57CE
	bl func_080078A4
	ldrh r1, [r4, #0x00]
	ldr r0, _080C57FC @ =0x0000FFFE
	ands r0, r1
	strh r0, [r4, #0x00]
_080C57CE:
	ldrh r1, [r4, #0x00]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0x00
	beq _080C57E0
	ldrh r1, [r4, #0x00]
	ldr r0, _080C5800 @ =0x0000FFEF
	ands r0, r1
	strh r0, [r4, #0x00]
_080C57E0:
	ldr r4, _080C5804 @ =0x0203C374
	movs r0, #0x00
	ldsb r0, [r4, r0]
	cmp r0, #0x01
	bne _080C57F2
	bl func_080C57A4
	movs r0, #0x00
	strb r0, [r4, #0x00]
_080C57F2:
	pop {r4}
	pop {r0}
	bx r0
_080C57F8: .4byte 0x03006C78
_080C57FC: .4byte 0x0000FFFE
_080C5800: .4byte 0x0000FFEF
_080C5804: .4byte 0x0203C374
.syntax divided
