.syntax unified
	.align 2, 0
	.global func_080FF2B8
	.thumb
	.thumb_func
	.type func_080FF2B8, %function
func_080FF2B8: @ 080FF2B8
	push {r4, lr}
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	ldr r0, _080FF2E0 @ =0x02039BB0
	ldr r0, [r0, #0x08]
	movs r1, #0x08
	ands r0, r1
	ldr r4, _080FF2E4 @ =0x09A02EFC
	cmp r0, #0x00
	bne _080FF2CE
	ldr r4, _080FF2E8 @ =0x09A020FC
_080FF2CE:
	ldr r0, _080FF2EC @ =0x020350FA
	lsls r1, r2, #0x10
	asrs r1, r1, #0x10
	movs r2, #0x00
	ldsh r0, [r0, r2]
	cmp r1, r0
	bge _080FF2F0
	lsls r0, r1, #0x08
	b _080FF2F4
_080FF2E0: .4byte 0x02039BB0
_080FF2E4: .4byte 0x09A02EFC
_080FF2E8: .4byte 0x09A020FC
_080FF2EC: .4byte 0x020350FA
_080FF2F0:
	movs r0, #0xD0
	lsls r0, r0, #0x04
_080FF2F4:
	adds r4, r4, r0
	movs r0, #0x00
	bl GetBgCharBase
	adds r1, r0, #0x0
	adds r1, #0x20
	movs r2, #0x80
	lsls r2, r2, #0x01
	adds r0, r4, #0x0
	bl RequestDma3Copy
	pop {r4}
	pop {r0}
	bx r0
.syntax divided
