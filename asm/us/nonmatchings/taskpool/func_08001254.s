.syntax unified
	.align 2, 0
	.global func_08001254
	.thumb
	.thumb_func
	.type func_08001254, %function
func_08001254: @ 08001254
	push {r4, lr}
	ldr r4, _0800128C @ =0x0300749C
	ldrb r1, [r4, #0x00]
	movs r0, #0x01
	ands r0, r1
	cmp r0, #0x00
	beq _0800126E
	bl func_08000F94
	ldrb r1, [r4, #0x00]
	movs r0, #0xFE
	ands r0, r1
	strb r0, [r4, #0x00]
_0800126E:
	ldrb r1, [r4, #0x00]
	movs r0, #0x02
	ands r0, r1
	cmp r0, #0x00
	bne _080012A0
	ldr r0, _08001290 @ =0x03006C78
	ldrh r1, [r0, #0x00]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0x00
	beq _08001294
	bl func_08004938
	b _08001298
	.byte 0x00, 0x00
_0800128C: .4byte 0x0300749C
_08001290: .4byte 0x03006C78
_08001294:
	bl FlushDma3Queue
_08001298:
	bl func_08002F50
	bl CommitDisplayRegs
_080012A0:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
